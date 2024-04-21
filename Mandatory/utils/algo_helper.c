/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:04:21 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 00:05:00 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_max(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*max_node;
	int		max;

	max_node = NULL;
	max = INT_MIN;
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

void	ft_index(t_stack *head, size_t size)
{
	t_stack	*tmp;

	if (!head)
		return ;
	while (size > 0)
	{
		tmp = ft_max(head);
		if (!tmp)
			break ;
		tmp->index = size - 1;
		size--;
	}
}

void	ft_list_position(t_stack *a)
{
	size_t	i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		tmp->postion = i;
		i++;
		tmp = tmp->next;
	}
}

int	find_bigest_index(t_stack *b)
{
	t_stack	*tmp;
	int		max_post;
	int		index;

	tmp = b;
	max_post = -1;
	index = -1;
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

void	algo_implement(t_stack **a, t_stack **b)
{
	int	bigest_index_post;
	int	k;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
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
