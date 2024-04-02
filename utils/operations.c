/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:06:55 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/02 16:37:50 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void swap(t_stack **a, int n)
{
    if (!a || !*a || !(*a)->next)
        return ;
    t_stack *tmp;

    tmp = (*a)->next;
    (*a)->next = tmp->next;

    lst_add_front(a, tmp);
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

void pb(t_stack **a, t_stack **b)
{
    if (!a || !*a || !b)
        return ;
    t_stack *tmp = *a;
    (*a) = (*a)->next;
    if (!*b)
    {
        *b = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *b;
        *b = tmp;
    }
    write(1, "pb\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
    if (!a || !b || !*b)
        return ;
    t_stack *tmp = *b;
    (*b) = (*b)->next;
    if (!*a)
    {
        *a = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *a;
        *a = tmp;
    }
    write(1, "pa\n", 3);
}


void rotate(t_stack **a, int n)
{
    if (!a || !*a || !(*a)->next)
        return ;
    t_stack *tmp = *a;
    t_stack *last = lst_last(*a);

    *a = tmp->next;
    last->next = tmp;
    last->next->next = NULL;
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
void reverse_rotate(t_stack **a, int n)
{
    if (!*a || !(*a)->next)
        return ;
    t_stack *tmp = *a;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    lst_add_front(a, tmp->next);
    tmp->next = NULL;
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