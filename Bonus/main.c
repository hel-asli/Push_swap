/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:25:08 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 22:47:27 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_handel(long *tab)
{
	write(2, "Error\n", 6);
	free(tab);
	exit(EXIT_FAILURE);
}

void	stack_init(long *tab, size_t size)
{
	t_stack	*a;
	t_stack	*b;
	size_t	k;

	a = NULL;
	b = NULL;
	k = 0;
	while (k < size && tab)
	{
		if (k == 0)
			a = stack_node_init((int)tab[k]);
		else
			stack_add_back(&a, stack_node_init((int)tab[k]));
		k++;
	}
	free(tab);
	read_inst(&a, &b);
	check_stack(a, b);
	stack_clear(&a);
	stack_clear(&b);
}

int	main(int ac, char **av)
{
	size_t	size;
	long	*tab;
	char	*str;
	char	**sp;

	check_args(ac, av);
	str = join_args(++av);
	sp = ft_split(str, ' ');
	if (!sp)
		return (free(str), write(2, "Error\n", 6), 1);
	ft_is_number(sp);
	size = tab_size(sp);
	tab = allocate_numbers(sp, str, size);
	if (!check_dup(tab, size))
		error_handel(tab);
	stack_init(tab, size);
	return (0);
}
