/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:04:39 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/25 08:46:47y hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

size_t ft_strlen(char *str)
{
	size_t n = 0;

	while (str[n])
	{
		n++;
	}

	return (n);
}

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

void lek(void)
{
	system("leaks a.out");
}

char *join_args(char **av)
{
	size_t count = count_chars(av);
	char *str = malloc(sizeof(char) * (count + 1));
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
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int check_dup(char **sp)
{
	long *tab;

	size_t i;
	size_t sp_size = tab_size(sp);
	tab = malloc(sizeof(long *) * (sp_size + 1));
	if (!tab)
	{
		ft_free(sp);
		return (1);
	}
	size_t k;

	k = 0;
	while (k < sp_size)
	{
		long nb = ft_atol(sp[k]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			printf("%ld\n", nb);
			return (0);
		}
		tab[k++] = nb;
	}
	i = 0;
	while (i < sp_size)
	{
		k = i + 1;
		while (k < sp_size)
		{
			if (tab[i] == tab[k])
			{
				return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}
int only_spaces(char *str)
{
	size_t s;
	char *tmp;

	s = 0;
	tmp = str;
	while (*str)
	{
		if (*str == ' ')
			s++;
		str++;
	}
	if (s == ft_strlen(tmp))
	{
		return (0);
	}
	return (1);
}

int main (int ac, char **av)
{
	int e = 1;
	while (av[e])
	{
		if (av[e][0] == 0 || !only_spaces(av[e]))
		{

			printf("Error");
			exit(EXIT_FAILURE);
		}
		e++;
	}
	char *str = join_args(++av);
	char **sp = ft_split(str, ' ');
	if (ac == 1)
		return (1);
	int i = 0;
	int flag = 0;
	while (sp[i] && !flag)
	{
		if (!is_number(sp[i]))
		{
			flag++;
		}
		i++;
	}

	// check for dup
	if (flag != 0 || !check_dup(sp))
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}

	return (0);
}

