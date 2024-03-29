/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:02:19 by hel-asli          #+#    #+#             */
/*   Updated: 2024/03/28 01:10:00 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
char	**ft_free(char **split);
void    ft_putstr_fd(char *str, int fd);
long    ft_atol(char *str);

# endif