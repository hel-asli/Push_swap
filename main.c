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


void error_handel(long *tab)
{
	write(1, "Error\n", 6);
	free(tab);
	exit(EXIT_FAILURE);
}

void stack_init(long *tab, size_t size)
{
	t_stack *a;
	t_stack *b;
	size_t	k;

	a = NULL;
	b = NULL;
	k = 0;
	while (k < size && tab)
	{
		if (k == 0)
			a = lst_init((int)tab[k]);
		else
		{
			lst_add_back(&a, lst_init((int)tab[k]));
		}
		k++;
	}
	rrr(&a, &b);
	print_lst(a);
	free(tab);
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

