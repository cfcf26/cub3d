/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:35:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 21:37:35 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	validate_map(int ac, char **av)
{
	int		fd;
	int		size[2];
	char	**tmp_map;

	tmp_map = NULL;
	fd = validate_file(ac, av);
	validate_texture_paths(fd);
	validate_floor_ceiling_colors(fd);
	validate_map_characters(fd);
	close(fd);
	check_map_size(av[1], size);
	close(fd);
	// make_map(av[1], &tmp_map);
	// close(fd);
	tmp_map = make_map2(av[1], size);
	close(fd);
	//validate_map_wall(tmp_map, size);
	validate_map_wall2(tmp_map, size);
}

void	parser(int ac, char **av)
{
	validate_map(ac, av);
}
