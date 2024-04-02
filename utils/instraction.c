/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:06:55 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/02 07:14:25 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// V.1 The rules
// • You have 2 stacks named a and b.
// • At the beginning:
// ◦ The stack a contains a random amount of negative and/or positive numbers
// which cannot be duplicated.
// ◦ The stack b is empty.
// • The goal is to sort in ascending order numbers into stack a. To do so you have the
// following operations at your disposal:
// sa (swap a): Swap the first 2 elements at the top of stack a. X
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b. X
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time. X
// pa (push a): Take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.


// sa
void swap(t_stack **a, int n)
{
    if (!a || !*a || !(*a)->next)
        return ;
    t_stack *tmp;

    tmp = (*a)->next;
    (*a)->next = tmp->next;
    // tmp ->next = *a;

    // *a = tmp;
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
        tmp->next = *b;
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
        tmp->next = *a;
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