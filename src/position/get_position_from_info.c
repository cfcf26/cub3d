/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_from_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:31:34 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:07:08 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"

/**
 * @brief get position from info
 * 
 * @details get position from info
 * 
 * @param info 
 */
static char	get_pos(t_position *position, const t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (ft_strchr("NSEW", info->map[i][j]) != NULL)
			{
				position->pos_y = j + 0.5;
				position->pos_x = i + 0.5;
				return (info->map[i][j]);
			}
		}
	}
	return (0);
}

/**
 * @brief get position
 * 
 * @details get position
 * 
 * @param position 
 * @param info 
 */
static void	get_dir(t_position *position, char dir)
{
	if (dir == 'N')
	{
		position->dir_x = 0;
		position->dir_y = -1;
	}
	else if (dir == 'S')
	{
		position->dir_x = 0;
		position->dir_y = 1;
	}
	else if (dir == 'E')
	{
		position->dir_x = 1;
		position->dir_y = 0;
	}
	else if (dir == 'W')
	{
		position->dir_x = -1;
		position->dir_y = 0;
	}
}

/**
 * @brief get plane
 * 
 * @details get plane
 * 
 * @param position 
 * @param dir 
 */
static void	get_plane(t_position *position, char dir)
{
	if (dir == 'N')
	{
		position->plane_x = 0.66;
		position->plane_y = 0;
	}
	else if (dir == 'S')
	{
		position->plane_x = -0.66;
		position->plane_y = 0;
	}
	else if (dir == 'E')
	{
		position->plane_x = 0;
		position->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		position->plane_x = 0;
		position->plane_y = -0.66;
	}
}

/**
 * @brief get player char
 * 
 * @details get player char
 * 
 * @param map 
 */
static void	get_player_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]) != NULL)
			{
				get_position()->player_char = map[i][j];
				return ;
			}
		}
	}
}

/**
 * @brief get position from info
 * 
 * @details get position from info
 * 
 */
void	get_position_from_info(void)
{
	t_position		*position;
	const t_info	*info = get_info();
	char			dir;

	position = get_position();
	dir = get_pos(position, info);
	get_dir(position, dir);
	get_plane(position, dir);
	get_player_char(info->map);
}
