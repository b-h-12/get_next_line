/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:05:25 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/28 17:44:54 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*ft_extract_line(char **str)
{
	int	i;
	char	*ret;

	i = 0;
    if (!(*str))
        return (NULL);
	while ((*str)[i] && (*str)[i] !='\n')
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = (*str)[i];
        i++;
	}
    ret[i] = '\n';
    ret[i + 1] = '\0';
    ft_cut_left(str);
    return (ret);
}

char    *get_next_line(int fd)
{
    static char *remainder = NULL;
    char    *buffer;
    int byte_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    byte_read = BUFFER_SIZE;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while(byte_read == BUFFER_SIZE && !ft_strchr(remainder, '\n'))
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read > 0)
        {
            buffer[byte_read] = '\0';
            ft_append(&remainder, buffer);
        }
    }
    free(buffer);
    if (byte_read < 0)
        return (NULL);
    if (ft_strchr(remainder, '\n'))
        return (ft_extract_line(&remainder));
    return (remainder);
}
