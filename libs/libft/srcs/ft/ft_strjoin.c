/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:22:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:29:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenate two strings in a allocated string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*ptr;

	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return ((void *)0);
	ptr = newstr;
	if (s1)
		while (*s1)
			*newstr++ = *s1++;
	if (s2)
		while (*s2)
			*newstr++ = *s2++;
	*newstr = '\0';
	return (ptr);
}
