/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:58:13 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/20 23:48:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes each node from this list node
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	while (*lst)
	{
		nxt = (**lst).next;
		if (del)
			del((**lst).content);
		free (*lst);
		*lst = nxt;
	}
}
