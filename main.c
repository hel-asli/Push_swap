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

void error_handel(char *str, long *tab, char **sp)
{
	printf("Error");
	free(str);
	free(tab);
	ft_free(sp);
	exit(EXIT_FAILURE);
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

long *ft_numbers(char **sp, size_t size)
{
	long *tab;
	tab = malloc(sizeof(long *) * (size + 1));
	if (!tab)
	{
		ft_free(sp);
		return (NULL);
	}
	size_t k;

	k = 0;
	while (k < size)
	{
		long nb = ft_atol(sp[k]);
		tab[k++] = nb;
	}
	return (tab);
}

int main (int ac, char **av)
{
	if (ac == 1)
		return (1);
	int j = 1;

	while (av[j])
	{
		if (av[j][0] == 0 || !only_spaces(av[j]))
		{

			printf("Error");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	char *str = join_args(++av);
	char **sp = ft_split(str, ' ');
	size_t size = tab_size(sp);
	long	*tab;
	int i = 0;
	int flag = 0;
	while (sp[i] && !flag)
	{
		if (!is_number(sp[i]))
		{
			flag++;
			break ;
		}
		i++;
	}
	// check for dup
	tab = NULL;
	if (flag == 0)
	{
		tab = ft_numbers(sp, size);
		if (!check_dup(tab, size))
			error_handel(str, tab, sp);
	}
	else if (flag > 0)
		error_handel(str, tab, sp);
	free(str);
	free(tab);
	ft_free(sp);
	return (0);
}

