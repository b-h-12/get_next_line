/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:05:25 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/25 20:06:52 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char	*leftover = NULL;
    char		*buffer;
    int			line_len;
    int			byte_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer = malloc(BUFFER_SIZE + 1)))
        return (NULL);
    line_len = contains_new_line(leftover);
    if (line_len > 0)
        return (extract_line(&leftover, line_len));
    byte_read = BUFFER_SIZE;
    while (line_len < 1 && byte_read == BUFFER_SIZE)
    {
        if ((byte_read = read(fd, buffer, BUFFER_SIZE)) < 0)
        {
            free(buffer);
            return (NULL);
        }
        leftover = ft_strjoin(leftover, buffer, byte_read);
        line_len = contains_new_line(leftover);
    }
    free(buffer);
    return (endl_checker(&leftover, line_len));
}
