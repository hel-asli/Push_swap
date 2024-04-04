/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:28:01 by hel-asli          #+#    #+#             */
/*   Updated: 2024/04/03 23:34:29 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str);

#endif