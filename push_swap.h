/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:02:19 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/02 17:45:40 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

// #define malloc(x) NULL

typedef struct s_stack
{
    int             index;
    int             postion;
    int             number;
    struct s_stack  *next;
} t_stack;

char	**ft_split(char const *s, char c);
char	**ft_free(char **split);
void    ft_putstr_fd(char *str, int fd);
long    ft_atol(char *str);
size_t ft_strlen(char *str);
size_t tab_size(char **str);
size_t count_chars(char **av);
char *join_args(char **av);
int is_number(char *str);
int check_dup(long *tab, size_t size);
t_stack *lst_init(int   nbr);
t_stack *lst_add_front(t_stack **root, t_stack *node);
void print_lst(t_stack *head);
void	lstclear(t_stack **lst);
void    lst_add_back(t_stack **root, t_stack *node);
void swap(t_stack **a, int n);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void rotate(t_stack **a, int n);
t_stack *lst_last(t_stack *root);
void rr(t_stack **a, t_stack **b);
void reverse_rotate(t_stack **a, int n);
void rrr(t_stack **a, t_stack **b);

int is_sorted(long *tab, size_t size);
int is_spaces(char *str); 
long *allocate_numbers(char **sp, char *str ,  size_t size);
void check_args(int ac, char **av);
void ft_is_number(char **sp);
int lst_size(t_stack *root);

# endif