/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:05:20 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/07 20:01:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterate a linked list modifying a allocated copy
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*cont;

	newlst = (void *)0;
	while (lst)
	{
		cont = lst->content;
		if (f)
			cont = f(cont);
		node = ft_lstnew(cont);
		if (!node)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
