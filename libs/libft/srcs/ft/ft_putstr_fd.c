/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 05:41:39 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/07 21:13:45 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Output a string in the gived file descriptor
int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (*s)
		len += write(fd, s++, 1);
	return (len);
}
