/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:15:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/20 20:49:33 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locate byte in byte string
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n --)
	{
		if (*(char *) s == (char) c)
			return ((void *) s);
		s++;
	}
	return (0);
}
