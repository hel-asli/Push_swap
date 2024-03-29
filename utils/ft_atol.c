/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:30:49 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/29 07:40:15 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
