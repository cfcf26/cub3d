/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:58:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:19:17 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_wall_validity(char **map, int x, int y)
{
	if (map[x][y] == '\0' || map[x][y] == ' ' || map[x][y] == '\n')
		write_err("Error : Map is not surrounded by walls (1)\n");
}

void	validate_map_walls(void)
{
	const char	not_wall[5] = "0NEWS";
	char		**map;
	int			x;
	int			y;

	map = get_info()->map;
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (ft_strchr(not_wall, map[x][y]))
			{
				check_wall_validity(map, x - 1, y);
				check_wall_validity(map, x + 1, y);
				check_wall_validity(map, x, y - 1);
				check_wall_validity(map, x, y + 1);
			}
		}
	}
}
