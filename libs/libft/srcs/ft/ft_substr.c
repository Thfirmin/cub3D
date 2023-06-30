/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:25:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:50:38 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocate a peace of a gived string begin ate start of len size
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	if (start > i)
		start = i;
	if (len > (i - start))
		len = (i - start);
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (len --)
		*(str + i++) = *(s + start++);
	*(str + i) = '\0';
	return (str);
}
