/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:25:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/14 10:54:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicate a string into a allocated string
char	*ft_strdup(const char *s1, t_mem **mem)
{
	char	*str;
	char	*ptr;

	str = ft_malloc((ft_strlen(s1) + 1), "ft_strdup", mem);
	if (!str)
		return (0);
	ptr = str;
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (ptr);
}
