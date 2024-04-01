/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:06:55 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/01 10:58:10 by hel-asli         ###   ########.fr       */
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
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
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
t_stack *sa(t_stack **a)
{
    if (!a)
        return (NULL);
    t_stack *tmp;

    tmp = (*a)->next;
    (*a)->next = tmp->next;
    // tmp ->next = *a;

    // *a = tmp;
    lst_add_front(a, tmp);
    return (*a);
}

t_stack *sb(t_stack **b)
{
    if (!b)
        return (NULL);
    t_stack *tmp;

    tmp = (*b)->next;
    (*b)->next = tmp->next;
    // tmp ->next = *a;

    // *a = tmp;
    lst_add_front(b, tmp);
    return (*a);
}

void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
}
