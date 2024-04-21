/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:30:49 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/21 02:19:23 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

void	pb_lowest_index(t_stack **a, t_stack **b, int lowest_index_post,
		int size)
{
	int	k;

	if (lowest_index_post == 0)
		pb(a, b);
	else if (lowest_index_post < (size / 2))
	{
		while (lowest_index_post > 0)
		{
			rotate(a);
			lowest_index_post--;
		}
		pb(a, b);
	}
	else
	{
		k = size - lowest_index_post;
		while (k > 0)
		{
			reverse_rotate(a);
			k--;
		}
		pb(a, b);
	}
}

long	ft_atol(char *str)
{
	long	nb;
	long	tmp;
	int		signe;

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
