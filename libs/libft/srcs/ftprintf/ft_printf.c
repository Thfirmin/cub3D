/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:21:13 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:37:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_putformatted_fd(char mask, va_list *ap, int fd);

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	if (!format)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += ft_putformatted_fd(*++format, &ap, 1);
		else
			len += ft_putchar_fd(*format, 1);
		format ++;
	}
	va_end(ap);
	return (len);
}

static int	ft_putformatted_fd(char mask, va_list *ap, int fd)
{
	int		len;
	char	*str;

	len = 0;
	if ((mask == 'd') || (mask == 'i'))
		len += ft_putnbr_fd(va_arg(*ap, int), fd);
	else if (mask == 'u')
		len += ft_putunbr_fd(va_arg(*ap, unsigned int), fd);
	else if ((mask == 'p') || (mask == 'x') || (mask == 'X'))
		len += ft_puthex_fd(va_arg(*ap, long unsigned int), (mask - 'X'), fd);
	else if (mask == 'c')
		len += ft_putchar_fd(va_arg(*ap, int), fd);
	else if (mask == '%')
		len += ft_putchar_fd('%', fd);
	else if (mask == 's')
	{
		str = va_arg(*ap, char *);
		if (!str)
			len += ft_putstr_fd("(null)", fd);
		else
			len += ft_putstr_fd(str, fd);
	}
	return (len);
}
