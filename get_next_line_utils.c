/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:06:11 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/29 17:59:21 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_append(char **s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return ;
	str = (char *)malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
	if (!str)
		return ;
	while (*s1 && (*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(*s1);
	*s1 = str;
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

void	ft_cut_left(char **str)
{
	char	*tmp;
	char	*right;
	int		i;

	i = 1;
	right = ft_strchr(*str, '\n');
	//printf("%s", right);
	tmp = malloc(sizeof(char) * (ft_strlen(right) + 1));
	//printf("%d", ft_strlen(right));
	if (!tmp)
		return ;
	while (right[i])
	{
		tmp[i] = right[i];
		//printf("%c", tmp[i]);
		i++;
	}
	//printf("%s", tmp);
	tmp[i] = '\0';
	//char *tmp2 = tmp;
	//printf("tmp = %s\n", tmp2);
	printf("%s", tmp);
	free(*str);
	*str = tmp;
}
