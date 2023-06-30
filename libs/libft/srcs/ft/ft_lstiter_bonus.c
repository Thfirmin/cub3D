/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:04:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/21 11:02:41 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterate a linked list modifying itself
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		if (f)
			f(lst->content);
		lst = lst->next;
	}
}
