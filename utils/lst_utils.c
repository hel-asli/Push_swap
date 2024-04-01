/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:11:04 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/01 08:04:40 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *lst_init(int   *nbr)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->number = nbr;
    node->next = NULL;
    return (node);
}

t_stack *lst_last(t_stack *root)
{
    if (!root)
        return NULL;
    while (root->next != NULL)
    {
        root = root->next;
    }

    return (root);
}
void    lst_add_back(t_stack **root, t_stack *node)
{
    if (!root)
        return ;
    t_stack *last;

    if (!*root)
        *root = node;
    else
    {
        last = lst_last(*root);
        last->next = node;
    }
}
size_t lst_size(t_stack *root)
{
    size_t size;
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

t_stack *lst_add_front(t_stack **root, t_stack *node)
{
    if (!root || !node)
        return (NULL);
    if (!*root)
        *root = node;
    else
    {
        node->next = *root;
        *root = node;
    }
    return (node);
}


void print_lst(t_stack *head)
{
    t_stack *c = head;

    while (c)
    {
        printf("%d\n",  *(c->number));
        c = c->next;
    }

}

void	lstclear(t_stack **lst)
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