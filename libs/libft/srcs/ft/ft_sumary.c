/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:13:50 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/14 10:12:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sumary(t_mem *mem)
{
	int	i;

	ft_printf ("\n--------------------| SUMARY |-------------------\n");
	ft_printf ("Bytes allocate'd: %d\n", ft_memsize(mem));
	i = -1;
	while (mem)
	{
		ft_printf ("----------------------------------------\n");
		ft_printf ("block[%d]:\t", ++i);
		ft_printf ("%p ", mem->ptr);
		ft_printf ("[%s]\n", mem->context);
		mem = mem->next;
	}
	ft_printf ("--------------------| END |-------------------\n");
}
