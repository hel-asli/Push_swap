/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:50:07 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 21:19:11 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		swap(stack, -1);
}

void	sort_three(t_stack **stack)
{
	int	bigest_index_post;

	ft_list_position(*stack);
	bigest_index_post = find_bigest_index(*stack);
	if (bigest_index_post == 0)
		rotate(stack, -1);
	else if (bigest_index_post == 1)
		reverse_rotate(stack, -1);
	if ((*stack)->number > ((*stack)->next->number))
		swap(stack, -1);
}

int	find_lowest_index(t_stack *stack)
{
	t_stack	*tmp;
	int		min_post;
	int		min;

	min = stack->number;
	tmp = stack->next;
	min_post = 0;
	while (tmp)
	{
		if (min > tmp->number)
		{
			min = tmp->number;
			min_post = tmp->postion;
		}
		tmp = tmp->next;
	}
	return (min_post);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	size;
	int	lowest_index_post;

	size = stack_size(*a);
	ft_list_position(*a);
	lowest_index_post = find_lowest_index(*a);
	pb_lowest_index(a, b, lowest_index_post, size);
	sort_three(a);
	while (*b)
		pa(b, a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;
	int	lowest_index_post;

	size = stack_size(*a);
	ft_list_position(*a);
	lowest_index_post = find_lowest_index(*a);
	pb_lowest_index(a, b, lowest_index_post, size);
	sort_four(a, b);
}
