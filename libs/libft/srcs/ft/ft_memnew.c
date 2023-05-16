/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:47:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/12 14:06:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mem_strdup(char *str);

t_mem	*ft_memnew(void *ptr, char *context)
{
	t_mem	*mem;

	mem = malloc(sizeof(t_mem));
	if (mem)
	{
		mem->ptr = ptr;
		mem->context = ft_mem_strdup(context);
		mem->next = 0;
	}
	return (mem);
}

static char	*ft_mem_strdup(char *str)
{
	char	*dup;
	int		len;

	len = -1;
	if (!str)
		return (0);
	while (*(str + len))
		len ++;
	dup = malloc(len + 1);
	len = -1;
	if (!dup)
		return (0);
	while (*(str + ++len))
		*(dup + len) = *(str + len);
	*(dup + len) = '\0';
	return (dup);
}
