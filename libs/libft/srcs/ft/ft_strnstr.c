/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:36:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:41:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locate a substring in a n lenght string
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;

	index = 0;
	if (!*needle)
		return ((char *) haystack);
	while ((index <= len) && *haystack)
	{
		if (!*(needle + index))
			return ((char *)haystack);
		else if (*(haystack + index) == *(needle + index))
			index ++;
		else if (*(haystack + index) != *(needle + index))
		{
			index = 0;
			haystack ++;
			len --;
		}
	}
	return (0);
}
