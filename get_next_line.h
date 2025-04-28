/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:05:47 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/28 17:22:43 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 64
#  endif

# include <stdlib.h>
# include <unistd.h>

int	ft_strlen(char *str);
void	ft_append(char **s1, char const *s2);
void	ft_cut_left(char **str);
char    *get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
char	*ft_strdup(const char *s);

#endif