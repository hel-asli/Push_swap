/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:06:55 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/17 18:09:07 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"


void swap(t_stack **s)
{
    if (!s || !*s || !(*s)->next)
        return ;
    t_stack *tmp;

    tmp = (*s)->next;
    (*s)->next = tmp->next;

    tmp->next = *s;
    *s = tmp;
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
}


void push(t_stack **dst, t_stack **src)
{
    if (!src || !*src)
        return ;

    t_stack *tmp = *src;
    *src = (*src)->next;
    tmp->next = *dst;
    *dst = tmp;
}
void pb(t_stack **a, t_stack **b)
{
    push(b, a);
}

void pa(t_stack **b, t_stack **a)
{
    push(a, b);
}


void rotate(t_stack **s)
{
    if (!s || !*s || !(*s)->next)
        return ;
    t_stack *tmp = *s;
    t_stack *last;
    *s = (*s)->next;
    tmp->next = NULL;

    last = stack_last(*s);
    last->next = tmp;
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}
void reverse_rotate(t_stack **s)
{
    if (!s || !*s || !(*s)->next)
        return ;
    t_stack *tmp = *s;
    t_stack *prev;
    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    prev->next = NULL;
    tmp->next = *s;
    *s = tmp;
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}