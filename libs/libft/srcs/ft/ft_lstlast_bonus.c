/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:04:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterate a linked list and return her last node
t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
