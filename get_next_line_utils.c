/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamoum <bhamoum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:06:11 by bhamoum           #+#    #+#             */
/*   Updated: 2025/04/25 19:58:11 by bhamoum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2, int len2)
{
    char	*str;
    size_t	i;
    size_t	j;
    int	len1;

    len1 = ft_strlen(s1);
    str = (char *)malloc(len1 + len2 + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (s1 && i < len1)
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2 && j < len2)
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    free(s1);
    return (str);
}

int	contains_new_line(const char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i ++;
	if (str[i] == '\n')
		return (i + 1);
	return (0);
}

char	*extract_line(char **leftover, int len)
{
	char	*str;
	char	*remainder;
	int	i;
	
	if (len < 1 || !leftover || !*leftover)
        return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while ((*leftover)[i] && i < len)
	{
		str[i] = (*leftover)[i];
		i++;
	}
	str[i] = '\0';
	remainder = ft_strjoin("", *leftover + i, ft_strlen(*leftover + i));
	free(*leftover);
	*leftover = remainder;
	return (str);
}

char	*endl_checker(char **leftover, int line_len)
{
    if (line_len > 0)
        return (extract_line(leftover, line_len));
    return (*leftover);
}
