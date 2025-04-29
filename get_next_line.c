/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:05:25 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/29 17:44:02 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static char	*ft_extract_line(char **str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(*str))
		return (NULL);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
	{
		ret[i] = (*str)[i];
		//printf("1");
		i++;
	}
	ret[i] = '\n';
	ret[i + 1] = '\0';
	//printf("%s", ret);
	ft_cut_left(str);
	//printf("%s", *str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*buffer;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byte_read = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (byte_read == BUFFER_SIZE && !ft_strchr(remainder, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read > 0)
		{
			buffer[byte_read] = '\0';
			ft_append(&remainder, buffer);
		}
	}
	//printf("%s ", remainder);
	//printf("%s ", ft_strchr(remainder, '\n'));
	free(buffer);
	if (byte_read < 0)
		return (NULL);
	if (ft_strchr(remainder, '\n'))
		{
			//printf("%s ", ft_extract_line(&remainder));
			return (ft_extract_line(&remainder));
		}
		
	return (remainder);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	//printf("%s", 
	get_next_line(fd);
	close(fd);
	return (0);
}
