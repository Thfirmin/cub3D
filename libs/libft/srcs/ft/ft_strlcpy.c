/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:34:03 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:30:54 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Size-bounded string copying
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	t_size;

	t_size = ft_strlen(src);
	if (!dstsize)
		return (t_size);
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize --;
	}
	if (dstsize > 0 || !*src)
		*dst = '\0';
	return (t_size);
}
