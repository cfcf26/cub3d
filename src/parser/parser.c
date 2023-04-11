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

	fd = validate_file(ac, av);
	validate_texture_paths(fd);
	validate_floor_ceiling_colors(fd);
	validate_map_characters(fd);
	close(fd);
}

void	parser(int ac, char **av)
{
	validate_map(ac, av);
}
