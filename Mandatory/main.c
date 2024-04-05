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

void	error_handel(long *tab)
{
	write(2, "Error\n", 6);
	free(tab);
	exit(EXIT_FAILURE);
}

void	start_sorting(t_stack **a, t_stack **b, size_t size)
{
	int	i = 0;
	int	range = 16;
	if (size > 100)
		range = 33;

	while (stack_size(*a))
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((i + range) > (*a)->index)
		{
			pb(a, b);
			rotate(b, 1);
			i++;
		}
		else
			rotate(a, -1);
	}
	algo_implement(a, b);
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
			a = stack_node_init((int)tab[k]);
		else
			stack_add_back(&a, stack_node_init((int)tab[k]));
		k++;
	}
	free(tab);
	ft_index(a, size);

	if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5) 
		sort_five(&a, &b);
	else
		start_sorting(&a, &b, size);
	stack_clear(&a);
	stack_clear(&b);
}

void lek(void)
{
	system("leaks push_swap");
}


int main (int ac, char **av)
{
	size_t size;
	long	*tab;
	char	*str;
	char	**sp;
	

	// atexit(lek);  
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
