/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:30:49 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/02 16:33:29 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void ft_putstr_fd(char *str, int fd)
{
    while (*str)
    {
        write(fd, str, 1);
        str++;
    }
}

size_t ft_strlen(char *str)
{
    size_t n;
    
    n = 0;
    while (*str)
    {
        n++;
        str++;
    }

    return (n);
}

long ft_atol(char *str)
{
    long nb;
    long tmp;
    int signe;

    signe = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            signe *= -1;
        str++;
    }

    nb = 0;
    while (*str && (*str >= '0' && *str <= '9'))
    {
        tmp = (nb * 10) + (*str - 48);
        if (tmp < nb && signe == 1)
            return (LONG_MAX);
        if (tmp < nb && signe == -1)
            return (LONG_MIN);
        nb = tmp;
        str++;
    }

    return (nb * signe);
}
