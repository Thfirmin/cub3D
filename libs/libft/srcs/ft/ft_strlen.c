/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:35:17 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:33:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Find length of string
size_t	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	if (str)
		while (*(str + count))
			count ++;
	return (count);
}
