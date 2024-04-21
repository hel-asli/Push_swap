/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:51:42 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 22:57:19 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_sorted(long *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_spaces(char *str)
{
	size_t	s;
	char	*tmp;

	s = 0;
	tmp = str;
	while (*str)
	{
		if (*str == ' ')
			s++;
		str++;
	}
	if (s == ft_strlen(tmp))
		return (0);
	return (1);
}

long	*allocate_numbers(char **sp, char *str, size_t size)
{
	long	*tab;
	long	nb;
	size_t	k;

	tab = malloc(sizeof(long *) * (size + 1));
	if (!tab)
	{
		ft_free(sp);
		return (NULL);
	}
	k = 0;
	while (k < size)
	{
		nb = ft_atol(sp[k]);
		tab[k++] = nb;
	}
	ft_free(sp);
	free(str);
	return (tab);
}

void	check_args(int ac, char **av)
{
	int	j;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	j = 1;
	while (av[j])
	{
		if (av[j][0] == 0 || !is_spaces(av[j]))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	ft_is_number(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		if (!is_number(sp[i]))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
