/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:30:49 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/29 02:41:02 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long ft_atol(char *str)
{
    long nb;
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
        nb *= 10;
        nb += *str - 48;
        str++;
    }

    return (nb * signe);
}
