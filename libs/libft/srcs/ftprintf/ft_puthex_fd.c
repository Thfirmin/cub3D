/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:44:31 by thfirmin          #+#    #+#             */
/*   Updated: 2022/11/07 13:17:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_puthex_fd(long unsigned int hex, char mode, int fd)
{
	int	len;

	len = 0;
	if (mode == ('p' - 'X'))
	{
		len += ft_putstr_fd("0x", fd);
		mode = 32;
	}
	if (hex >= 16)
		len += ft_puthex_fd((hex / 16), mode, fd);
	if ((hex % 16) < 10)
		len += ft_putchar_fd(('0' + (hex % 16)), fd);
	else
		len += ft_putchar_fd((('A' + mode) + ((hex % 16) - 10)), fd);
	return (len);
}
