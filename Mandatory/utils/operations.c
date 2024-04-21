/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:06:55 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/20 00:31:32 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **s, int n)
{
	t_stack	*tmp;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	tmp->next = *s;
	*s = tmp;
	if (n == -1)
		write(1, "sa\n", 3);
	else if (n == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 2);
	swap(b, 2);
	write(1, "ss\n", 3);
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	pa(t_stack **b, t_stack **a)
{
	push(a, b);
	write(1, "pa\n", 3);
}
