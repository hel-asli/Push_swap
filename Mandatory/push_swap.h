/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:02:19 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/05 08:14:13 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				postion;
	int				number;
	struct s_stack	*next;
}	t_stack;

// parsing function 

int		is_sorted(long *tab, size_t size);
int		is_spaces(char *str);
long	*allocate_numbers(char **sp, char *str, size_t size);
void	check_args(int ac, char **av);
void	ft_is_number(char **sp);
int		is_number(char *str);
int		check_dup(long *tab, size_t size);

// operations 

void	swap(t_stack **a, int n);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	rotate(t_stack **a, int n);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a, int n);
void	rrr(t_stack **a, t_stack **b);

// utils

char	**ft_split(char const *s, char c);
char	**ft_free(char **split);
void	ft_putstr_fd(char *str, int fd);
long	ft_atol(char *str);
size_t	ft_strlen(char *str);
size_t	tab_size(char **str);
size_t	count_chars(char **av);
char	*join_args(char **av);

// stack utils 

t_stack	*stack_node_init(int nbr);
void	stack_clear(t_stack **lst);
t_stack	*stack_last(t_stack *root);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *root);
t_stack	*ft_max(t_stack *head);
void	ft_index(t_stack *head, size_t size);
void	ft_list_position(t_stack *a);
int		find_bigest_index(t_stack *b);

// sort 

void	sort_two(t_stack **stack);
void	algo_implement(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

#endif
