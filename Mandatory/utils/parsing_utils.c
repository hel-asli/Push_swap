/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 05:53:43 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/03 22:56:26 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t tab_size(char **str)
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

size_t count_chars(char **av)
{
	int t;

	if (!*av)
		return (0);
	t = 0;
	while (*av)
	{
		t += ft_strlen(*av) + 1;
		av++;
	}
	return (t);
}


char *join_args(char **av)
{
	size_t count = count_chars(av);
	char *str = malloc(sizeof(char) * (count + 1));
	(void)count;
	if (!str)
		return (NULL);
	int k = 0;
	while (*av)
	{
		char *tmp = *av;
		while (*tmp)
		{
			str[k++] = *tmp;
			tmp++;
		}
		str[k++] = 32;
		av++;
	}
	str[k] = 0;
	return str;
}

int is_number(char *str)
{
	if ((*str == '-' && *(str + 1) && *(str + 1) != 32))
		str++;
	else if ((*str == '+' && *(str + 1) && *(str + 1) != 32))
		str++;
	
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int check_dup(long *tab, size_t size)
{
	size_t i;
	size_t k;
	
	i = 0;
	while (i < size)
	{
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			return (0);
		k = i + 1;
		while (k < size)
		{
			if ((tab[i] == tab[k]) || (tab[k] > INT_MAX || tab[k] < INT_MIN))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}