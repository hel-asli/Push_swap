/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:28:01 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/21 02:16:26 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				postion;
	int				number;
	struct s_stack	*next;
}	t_stack;

// get_next_line
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str);

// parsing function 

int		is_sorted(long *tab, size_t size);
int		is_spaces(char *str);
long	*allocate_numbers(char **sp, char *str, size_t size);
void	check_args(int ac, char **av);
void	ft_is_number(char **sp);
int		is_number(char *str);
int		check_dup(long *tab, size_t size);

// operations 

void	swap(t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a);
void	ss(t_stack **a, t_stack **b);
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
int		check_operation(char *str);
void	excute_op(char *str, t_stack **a, t_stack **b);
void	check_stack(t_stack *a, t_stack *b);
int		read_inst(t_stack **a, t_stack **b);
int		ft_strcmp(char *s1, char *s2);

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

#endif
