/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:16:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 12:17:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Turn a integer number in a numeric string

static int	ft_nbrlen(int n);

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	aux;

	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
		aux = -n;
	else
		aux = n;
	*(str + len) = '\0';
	while (len--)
	{
		*(str + len) = ((aux % 10) + '0');
		aux /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}

static int	ft_nbrlen(int n)
{
	unsigned int	aux;
	int				len;

	len = 0;
	if ((n < 0) && ++len)
		aux = -n;
	else
		aux = n;
	if (aux >= 10)
		len += ft_nbrlen((aux / 10));
	len ++;
	return (len);
}
