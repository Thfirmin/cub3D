/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:26:06 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/09 00:36:11 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	error_menu(char **argv, int argc)
{
	int	fd;

	fd = -1;
	error_argc(argc);
	fd = error_permission(argv[1]);
	error_filename(argv[1]);
	return (fd);
}

void	error_argc(int argc)
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

int	error_permission(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(argv);
		exit(0);
	}
	return (fd);
}

void	error_filename(char *argv)
{
	int		size;
	int		start;
	char	*res;

	size = ft_strlen(argv);
	start = size - 4;
	res = ft_substr(argv, start, size);
	if (ft_strncmp(res, ".cub", 4))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The extension of map must be .cub\n", 2);
		exit(0);
	}
	free(res);
}
