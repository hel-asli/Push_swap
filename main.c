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

t_stack *ft_max (t_stack *head)
{
	t_stack *tmp;
	t_stack *max_node;

	max_node = NULL;
	int max = INT_MIN;
	tmp = head;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->number >= max)
		{
			max = tmp->number;
			max_node = tmp;
		}
		tmp = tmp->next;
	}

	return (max_node);
}

void ft_index(t_stack *head, size_t size)
{
	t_stack *tmp;
	if (!head)
		return ;
	while (size > 0)
	{
		tmp = ft_max(head);
		if (!tmp)
			break;
		tmp->index = size - 1;
		size--;
	}
}

void ft_list_position(t_stack *a)
{
	size_t i = 0;
	t_stack *tmp;

	tmp = a;
	while(tmp)
	{
		tmp->postion = i;
		i++;
		tmp = tmp->next;
	}
}

int find_bigest_index(t_stack *b)
{
	t_stack *tmp;
	int max_post = -1;
	int index = -1;

	tmp = b;
	while (tmp)
	{
		if (tmp->index > index)
		{
			index = tmp->index;
			max_post = tmp->postion;
		}
		tmp = tmp->next;
	}
	return (max_post);
}
void algo_implement(t_stack **a, t_stack **b)
{
	int bigest_index_post;
	int k;
	int size;

	while (*b)
	{
		size = lst_size(*b);
		ft_list_position(*b);
		bigest_index_post = find_bigest_index(*b);

		if (bigest_index_post == 0)
			pa(b, a);
		else if (bigest_index_post < (size / 2))
		{
			while (bigest_index_post--)
				rotate(b, 1);
			pa(b, a);
		}
		else
		{
			k = size - bigest_index_post;
			while (k--)
				reverse_rotate(b, 1);
			pa(b, a);
		}
	}
}


void start_sorting(t_stack **a, t_stack **b, size_t size)
{
	int i = 0;
	int	range = 15;
	if (size > 100)
		range = 22;

	while (lst_size(*a))
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
			a = lst_init((int)tab[k]);
		else
		{
			lst_add_back(&a, lst_init((int)tab[k]));
		}
		k++;
	}
	ft_index(a, size);
	free(tab);
	start_sorting(&a, &b, size);
	// printf("stack a:");
	print_lst(b);
	// print_lst(a);
	lstclear(&a);
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
