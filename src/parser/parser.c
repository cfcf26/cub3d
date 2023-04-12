/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:35:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:19:36 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	validate_file_contents(int ac, char **av)
{
	int		fd;

	validate_file(ac, av);
	fd = open(av[1], O_RDONLY);
	validate_texture_paths(fd);
	validate_floor_ceiling_colors(fd);
	validate_map_characters(fd);
	close(fd);
}

static void	get_info_from_file(char *file_name)
{
	int	fd;

	get_info()->file_name = file_name;
	get_map_size(file_name);
	fd = open(file_name, O_RDONLY);
	get_texture_paths(fd);
	get_floor_ceiling_color(fd);
	get_map(fd);
	close(fd);
}

void	parser(int ac, char **av)
{
	validate_file_contents(ac, av);
	get_info_from_file(av[1]);
	validate_map_walls();
}
