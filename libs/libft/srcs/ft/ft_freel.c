/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:12:16 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/13 13:20:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freel(t_mem **mem)
{
	t_mem	*nxt;

	if (!mem)
		return ;
	while (*mem)
	{
		nxt = (**mem).next;
		free ((**mem).ptr);
		free ((**mem).context);
		free (*mem);
		*mem = nxt;
	}
}
