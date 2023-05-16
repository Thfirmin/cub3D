/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:30 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/08 14:19:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MASK "cspdiuxX%"
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);

int	ft_puthex_fd(long unsigned int hex, char mode, int fd);
int	ft_putunbr_fd(unsigned int unbr, int fd);

#endif
