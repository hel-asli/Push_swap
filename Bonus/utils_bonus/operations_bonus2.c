/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:55:04 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 23:05:19 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rotate(t_stack **s)
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
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack **s)
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
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
