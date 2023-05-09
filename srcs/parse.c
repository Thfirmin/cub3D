/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:26:06 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/08 23:49:32 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error_menu(char **argv, int argc)
{
	error_argc(argc);
	error_filename(argv[1]);
}

void	error_argc(int	argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The game must be initialized ", 2); 
		ft_putstr_fd("with the following arguments:\n", 2);
		ft_putstr_fd("./cub3d filename.cub\n", 2);
		exit(0);
	}
}

void	error_filename(char *argv)
{
	printf("%s\n", argv);
}
