/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:30:45 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 00:32:10 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **s, int n)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = NULL;
	last = stack_last(*s);
	last->next = tmp;
	if (n == -1)
		write(1, "ra\n", 3);
	else if (n == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 2);
	rotate(b, 2);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack **s, int n)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = *s;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *s;
	*s = tmp;
	if (n == -1)
		write(1, "rra\n", 4);
	else if (n == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 2);
	reverse_rotate(b, 2);
	write(1, "rrr\n", 4);
}
