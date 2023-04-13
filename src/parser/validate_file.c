/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:52:51 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/14 01:46:57 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	validate_file_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		write_err("Error : File open failed (1)\n");
	close(fd);
}

static void	validate_arguments(int ac)
{
	if (ac != 2)
		write_err("Error : Wrong number of arguments (1)\n");
}

void	validate_file(int ac, char **av)
{
	validate_arguments(ac);
	validate_file_extension(av[1], ".cub");
	validate_file_open(av[1]);
}
