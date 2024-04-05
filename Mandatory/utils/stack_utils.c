/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:11:04 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/04 03:34:48 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *stack_node_init(int   nbr)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->number = nbr;
    node->index = -1;
    node->next = NULL;
    return (node);
}

t_stack *stack_last(t_stack *root)
{
    if (!root)
        return NULL;
    while (root->next != NULL)
    {
        root = root->next;
    }

    return (root);
}
int stack_size(t_stack *root)
{
    int size;
    if (!root)
        return (0);

    size = 0;
    while (root)
    {
        size++;
        root = root->next;
    }

    return (size);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

    if (*stack == NULL)
    {
        *stack = new;
    }
    else
    {
        last = stack_last(*stack);
        last->next = new;
    }
}

void	stack_clear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current -> next;
		free(tmp);
	}
	*lst = NULL;
}