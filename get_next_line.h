/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:05:47 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/25 19:58:18 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 64
#  endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int	ft_strlen(const char *str);
int	contains_new_line(const char *str);
char	*ft_strjoin(const char *s1, const char *s2, int len2);
char	*extract_line(char **leftover, int len);
char	*endl_checker(char **leftover, int line_len);

#endif