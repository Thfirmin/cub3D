/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:49:21 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/23 15:26:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (!str)
		str = gnl_calloc(1, 1);
	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
	{
		free(str);
		str = (void *)0;
		return (0);
	}
	str = read_line(fd, str);
	line = take_line(str);
	str = clean_buffer(str);
	return (line);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = gnl_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (str);
		return (0);
	}
	while (!gnl_strchr(str, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		str = gnl_strjoin(str, buffer);
		if ((bytes < BUFFER_SIZE && *str) || !str)
			break ;
		else if (*str == '\0' && bytes <= 0)
		{
			free (str);
			str = (void *)0;
			break ;
		}
	}
	free(buffer);
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*newstr;

	newstr = (void *)0;
	i = 0;
	len = (gnl_strlen(s1) + gnl_strlen(s2));
	newstr = gnl_calloc((len + 1), sizeof(char));
	if (!newstr)
	{
		free (s1);
		return (0);
	}
	while (*(s1 + i))
	{
		newstr[i] = s1[i];
		i ++;
	}
	if (s2)
		while (*s2)
			newstr[i++] = *s2++;
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*take_line(char *str)
{
	char	*line;
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\n' && str[len])
		len ++;
	if (str[len] == '\n')
		len ++;
	line = gnl_calloc((len + 1), sizeof(char));
	if (!line)
		return (0);
	len = 0;
	while (str[len] != '\n' && str[len])
	{
		line[len] = str[len];
		len ++;
	}
	if (str[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*clean_buffer(char *buffer)
{
	size_t	len;
	char	*str;
	size_t	i;

	len = 0;
	i = 0;
	if (!buffer)
		return (0);
	while (buffer[len] != '\n' && buffer[len])
		len ++;
	if (buffer[len] == '\n')
		len ++;
	str = gnl_calloc((gnl_strlen(buffer + len) + 1), sizeof(char));
	if (!str)
		return (0);
	while (buffer[len])
		str[i++] = buffer[len++];
	str[i] = '\0';
	free(buffer);
	return (str);
}
