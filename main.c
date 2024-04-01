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

int is_sorted(long *tab, size_t size)
{
	size_t i = 0;

	while (i < size - 1)
	{
		if (tab[i] >  tab[i+1])
				return (0);
		i++;
	}
	return (1);
}
void error_handel(long *tab)
{
	write(1, "Error\n", 6);
	free(tab);
	exit(EXIT_FAILURE);
}

int is_spaces(char *str)
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
		return (0);
	return (1);
}

long *allocate_numbers(char **sp, char *str ,  size_t size)
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
	ft_free(sp);
	free(str);
	return (tab);
}

void check_args(int ac, char **av)
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

void ft_is_number(char **sp)
{
	int i;

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

void lek_wli_elik(void)
{
	system("leaks push_swap");
}
void del(void *content)
{
	free(content);
}
void stack_init(long *tab, size_t size)
{
	t_stack *a;
	t_stack *b;
	size_t	k;

	a = NULL;
	b = NULL;
	k = 0;
	while (k < size)
	{
		if (k == 0 && tab[k])
			a = lst_init((int)tab[k]);
		else
		{
			lst_add_back(&a, lst_init((int)tab[k]));
		}
		k++;
	}
	free(tab);
	sa(&a);
	print_lst(a);
}

int main (int ac, char **av)
{
	size_t size;
	long	*tab;
	char	*str;
	char	**sp;
	

	// atexit(lek_wli_elik);  
	check_args(ac, av);
	str= join_args(++av);
	sp = ft_split(str, ' ');
	if (!sp)
		return (free(str), write(2, "Error\n", 6), 1);
	ft_is_number(sp);
	size = tab_size(sp);
	tab = allocate_numbers(sp, str, size);
	if (!check_dup(tab, size))
		error_handel(tab);
	if (is_sorted(tab, size))
		return (free(tab), exit(EXIT_SUCCESS), 0);
	stack_init(tab, size);
	return 0;
}

