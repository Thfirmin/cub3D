/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:06:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/14 10:52:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size, char *context, t_mem **mem)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr && mem)
		ft_memadd_back(mem, ft_memnew(ptr, context));
	return (ptr);
}
