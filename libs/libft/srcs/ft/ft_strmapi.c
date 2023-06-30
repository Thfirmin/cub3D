/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:16:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:36:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterate a string modifying a allocated copy
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	i = -1;
	while (*(s + ++i))
	{
		if (f)
			*(str + i) = f(i, *(s + i));
		else
			*(str + i) = *(s + i);
	}
	*(str + i) = '\0';
	return (str);
}
