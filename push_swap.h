/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:02:19 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/29 07:10:43 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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

# endif