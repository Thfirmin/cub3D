/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:37:47 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/16 16:37:59 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(int count, int size)
{
	char	*ptr;
	size_t	len;

	len = 0;
	ptr = malloc (count * size);
	if (!ptr)
		return (0);
	while (len < (unsigned int)(count * size))
		*(ptr + len++) = 0;
	return ((void *) ptr);
}

char	*gnl_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char) c)
			return (str);
		str ++;
	}
	return (0);
}

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str)
		while (*(str + len))
			len ++;
	return (len);
}
