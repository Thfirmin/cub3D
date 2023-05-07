/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:06:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 21:37:02 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Create a new node
t_list	*ft_lstnew(void *content, int value)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (0);
	(*node).content = content;
	(*node).value = value;
	(*node).next = (void *)0;
	return (node);
}
