/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:54:49 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/12 13:36:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  Add a node at the end of a list
void	ft_memadd_back(t_mem **mem, t_mem *new)
{
	t_mem	*node;

	node = *mem;
	if (node)
		while (node->next)
			node = node->next;
	if (!node)
		*mem = new;
	else
		node->next = new;
}
