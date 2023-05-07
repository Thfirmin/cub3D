/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:41:57 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 12:15:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locate last occurrence of character in string
char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = (ft_strlen(s) + 1);
	while (--count > -1)
		if (*(s + count) == (char) c)
			return ((char *)s + count);
	return (0);
}
