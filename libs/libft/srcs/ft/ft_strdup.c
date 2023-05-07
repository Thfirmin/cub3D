/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:25:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:23:22 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicate a string into a allocated string
char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*ptr;

	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	ptr = str;
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (ptr);
}
