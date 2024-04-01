/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:02:19 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/01 08:08:03 by hel-asli         ###   ########.fr       */
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
    int             *number;
    struct s_stack  *top;
    struct s_stack  *bottom;
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
t_stack *lst_init(int   *nbr);
t_stack *lst_add_front(t_stack **root, t_stack *node);
void print_lst(t_stack *head);
void	lstclear(t_stack **lst);
void    lst_add_back(t_stack **root, t_stack *node);

# endif