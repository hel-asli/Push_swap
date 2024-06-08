/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:48:13 by hel-asli          #+#    #+#             */
/*   Updated: 2024/06/08 14:43:51 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_operation(char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		return (1);
	if (!ft_strcmp(str, "sb\n"))
		return (1);
	if (!ft_strcmp(str, "ss\n"))
		return (1);
	if (!ft_strcmp(str, "pa\n"))
		return (1);
	if (!ft_strcmp(str, "pb\n"))
		return (1);
	if (!ft_strcmp(str, "ra\n"))
		return (1);
	if (!ft_strcmp(str, "rb\n"))
		return (1);
	if (!ft_strcmp(str, "rr\n"))
		return (1);
	if (!ft_strcmp(str, "rra\n"))
		return (1);
	if (!ft_strcmp(str, "rrb\n"))
		return (1);
	if (!ft_strcmp(str, "rrr\n"))
		return (1);
	return (0);
}

void	excute_op(char *str, t_stack **a, t_stack **b)
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

void	check_stack(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

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

void	err_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	read_inst(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	if (!str)
		return ;
	while (str)
	{
		if (check_operation(str))
			excute_op(str, a, b);
		else
			err_exit("Error\n");
		free(str);
		str = get_next_line(0);
		if (!str)
			return ;
	}
}
