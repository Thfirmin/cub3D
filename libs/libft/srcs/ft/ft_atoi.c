/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:37:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 10:39:40 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convert ASCII string to integer
int	ft_atoi(const char *str)
{
	int		atoinum;
	short	signal;

	signal = 1;
	atoinum = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal = (signal * -1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		atoinum = (atoinum * 10);
		atoinum = (atoinum + (*str - '0'));
		str++;
	}
	atoinum = (atoinum * signal);
	return (atoinum);
}
