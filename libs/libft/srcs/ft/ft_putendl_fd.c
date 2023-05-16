/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 05:46:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/07 21:12:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Output a string followed by a new line in the gived file descriptor
int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (*s)
		len += write(fd, s++, 1);
	len += write(fd, "\n", 1);
	return (len);
}
