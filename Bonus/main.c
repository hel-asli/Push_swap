/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:25:08 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/18 22:40:49 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_handel(long *tab)
{
	write(2, "Error\n", 6);
	free(tab);
	exit(EXIT_FAILURE);
}

int ft_strcmp(char *s1, char *s2)
{
        while (*s1 && *s1 == *s2)
        {
                s1++;
                s2++;
        }
        return (*s1 - *s2);
}

int check_operation(char *str)
{
    if (!ft_strcmp(str, "sa\n"))
        return 1;
    if (!ft_strcmp(str, "sb\n"))
        return 1;
    if (!ft_strcmp(str, "ss\n"))
        return 1;
    if (!ft_strcmp(str, "pa\n"))
        return 1;
    if (!ft_strcmp(str, "pb\n"))
        return 1;
    if (!ft_strcmp(str, "ra\n"))
        return 1;
    if (!ft_strcmp(str, "rb\n"))
        return 1;
    if (!ft_strcmp(str, "rr\n"))
        return 1;
    if (!ft_strcmp(str, "rra\n"))
        return 1;
    if (!ft_strcmp(str, "rrb\n"))
        return 1;
    if (!ft_strcmp(str, "rrr\n"))
        return 1;
    return 0;
}
void    excute_op(char *str, t_stack **a, t_stack **b)
{
    if (!ft_strcmp(str, "sa\n"))
        swap(a);
    else if (!ft_strcmp(str, "sb\n"))
        swap(b);
    else if (!ft_strcmp(str, "sb\n"))
        swap(b);
    else if (!ft_strcmp(str, "ss\n"))
        ss(a, b);
    else if (!ft_strcmp(str, "ra\n"))
        rotate(a);
    else if (!ft_strcmp(str, "rb\n"))
        rotate(b);
    else if (!ft_strcmp(str, "rra\n"))
        reverse_rotate(a);
    else if (!ft_strcmp(str, "rrb\n"))
        reverse_rotate(b);
    else if (!ft_strcmp(str, "rrr\n"))
        rrr(a, b);
    else if (!ft_strcmp(str, "pa\n"))
        pa(b, a);
    else if (!ft_strcmp(str, "pb\n"))
        pa(a, b);
    else
        return ;
}

void check_stack(t_stack *a, t_stack *b)
{
    t_stack *tmp;

    tmp = a;
    
    if (stack_size(b) != 0)
    {
        write(1, "KO\n", 3);
        return ;
    }
    while (tmp->next)
    {
        if (tmp->number > tmp->next->number)
        {
            write(1, "KO\n", 3);
            return ;
        }
        tmp = tmp->next;
    }
    write(1, "OK\n", 3);
}
int read_inst(t_stack **a, t_stack **b)
{
    char *str;

    str = get_next_line(0);
    while (str)
    {
        if (ft_strcmp(str, "\n") == 0)
            return (1);
        if (!str)
            return (write(2, "Error\n", 6), exit(EXIT_FAILURE), 0);
        else if (check_operation(str))
            excute_op(str, a, b);
        else
            return (write(2, "Error\n", 6), exit(EXIT_FAILURE), 0);
        free(str);
        str = get_next_line(0);
    }

    return (1);
}


void stack_init(long *tab, size_t size)
{
        t_stack *a;
        t_stack *b;
        size_t  k;

        a = NULL;
        b = NULL;
        k = 0;
        while (k < size && tab)
        {
                if (k == 0)
                        a = stack_node_init((int)tab[k]);
                else
                        stack_add_back(&a, stack_node_init((int)tab[k]));
                k++;
        }
        free(tab);
        read_inst(&a, &b);
        check_stack(a, b);
        stack_clear(&a);
        stack_clear(&b);
}


int main (int ac, char **av)
{
        size_t size;
        long    *tab;
        char    *str;
        char    **sp;


        check_args(ac, av);
        str= join_args(++av);
        sp = ft_split(str, ' ');
        if (!sp)
                return (free(str), write(2, "Error\n", 6), 1);
        ft_is_number(sp);
        size = tab_size(sp);
        tab = allocate_numbers(sp, str, size);
        if (!check_dup(tab, size))
                error_handel(tab);
        stack_init(tab, size);
        return 0;
}