/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:51:31 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/03 23:51:34 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void swap(t_stack **s, int n)
{
    if (!s || !*s || !(*s)->next)
        return ;
    t_stack *tmp;

    tmp = (*s)->next;
    (*s)->next = tmp->next;

    tmp->next = *s;
    *s = tmp;
    // lst_add_front(a, tmp);
    if (n == -1)
        write(1, "sa\n", 3);
    else if (n == 1)
        write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a, 2);
    swap(b, 2);
    write(1, "ss\n", 3);
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
    write(1, "pb\n", 3);
}

void pa(t_stack **b, t_stack **a)
{
    push(a, b);
    write(1, "pa\n", 3);
}


void rotate(t_stack **s, int n)
{
    if (!s || !*s || !(*s)->next)
        return ;
    t_stack *tmp = *s;
    t_stack *last;
    *s = (*s)->next;
    tmp->next = NULL;

    last = lst_last(*s);
    last->next = tmp;
    if (n == -1)
        write(1, "ra\n", 3);
    else if (n == 1)
        write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a, 2);
    rotate(b, 2);
    write(1, "rr\n", 3);
}
void reverse_rotate(t_stack **s, int n)
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
    if (n == -1)
        write(1, "rra\n", 4);
    else if (n == 1)
        write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a, 2);
    reverse_rotate(b, 2);
    write(1, "rrr\n", 4);
}