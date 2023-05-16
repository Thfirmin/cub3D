/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:13:14 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/14 10:53:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory for an array of nmemb elements of size bytes each.
// The memory is set to zero
void	*ft_calloc(size_t count, size_t size, char *context, t_mem **mem)
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
	if (mem)
		ft_memadd_back(mem, ft_memnew(head, context));
	return (head);
}
