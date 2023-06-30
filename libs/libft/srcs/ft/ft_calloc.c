/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:13:14 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 10:44:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory for an array of nmemb elements of size bytes each.
// The memory is set to zero
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*head;
	void	*ptr;

	total = count * size;
	if ((!count || !size) || ((total < count) || (total < size)))
		return (0);
	ptr = malloc(total);
	if (!ptr)
		return (0);
	head = ptr;
	while (total --)
		*(char *)ptr++ = '\0';
	return (head);
}
