/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:45:58 by thfirmin          #+#    #+#             */
/*   Updated: 2022/11/07 13:20:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putunbr_fd(unsigned int unbr, int fd)
{
	int	len;

	len = 0;
	if (unbr >= 10)
		len += ft_putunbr_fd((unbr / 10), fd);
	len += ft_putchar_fd(('0' + (unbr % 10)), fd);
	return (len);
}
