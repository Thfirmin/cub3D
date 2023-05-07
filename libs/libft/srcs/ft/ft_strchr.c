/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:25:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:22:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locate first occurrence of character in string
char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = -1;
	while (*(s + ++count))
		if (*(s + count) == (char) c)
			return ((char *) s + count);
	if (!c)
		return ((char *) s + count);
	else
		return (0);
}
