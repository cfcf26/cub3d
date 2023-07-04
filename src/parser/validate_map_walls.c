/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:58:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:09:12 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief check wall validity
 * 
 * @details check wall validity
 * 
 * @param map 
 * @param x 
 * @param y 
 */
static void	check_wall_validity(char **map, int x, int y)
{
	int	*width;
	int	height;

	width = get_info()->width;
	height = get_info()->height;
	if (x < 0 || x >= height || y < 0 || y >= width[x])
		parse_error(" Map is not surrounded by walls (2)");
	if (map[x][y] == '\0' || map[x][y] == ' ' || map[x][y] == '\n')
		parse_error(" Map is not surrounded by walls (1)");
}

/**
 * @brief validate map walls
 * 
 * @details validate map walls
 * 
 */
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
