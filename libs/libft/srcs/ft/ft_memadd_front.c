/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:57:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/12 13:37:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add a node at the beginning of a list
void	ft_memadd_front(t_mem **mem, t_mem *new)
{
	new->next = *mem;
	*mem = new;
}
