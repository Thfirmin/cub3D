/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:26:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:31:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Size-bounded string concatenation
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	t_size;

	t_size = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		t_size ++;
		dst ++;
		dstsize --;
	}
	while (dstsize >= 1)
	{
		if (dstsize == 1 || !*src)
		{
			*dst = '\0';
			break ;
		}
		*dst++ = *src++;
		dstsize --;
	}
	return (t_size);
}
