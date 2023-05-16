/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:33:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:26:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterate a string modifying itself
void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	count;

	count = -1;
	while (*(s + ++count))
		if (f)
			f(count, (s + count));
}
