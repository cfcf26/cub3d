/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:14:21 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 04:30:32 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	move_forward(void)
{
	const char	not_wall[5] = "0NEWS";
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(not_wall, info->map \
	[(int)(position->pos_x + position->dir_x * MOVE_SPEED +0.01)] \
	[(int)position->pos_y]))
		position->pos_x += position->dir_x * MOVE_SPEED;
	if (ft_strchr(not_wall, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y + position->dir_y * MOVE_SPEED +0.01)]))
		position->pos_y += position->dir_y * MOVE_SPEED;
}

void	move_backward(void)
{
	const char	not_wall[5] = "0NEWS";
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(not_wall, info->map \
	[(int)(position->pos_x - position->dir_x * MOVE_SPEED -0.01)] \
	[(int)position->pos_y]))
		position->pos_x -= position->dir_x * MOVE_SPEED;
	if (ft_strchr(not_wall, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y - position->dir_y * MOVE_SPEED -0.01)]))
		position->pos_y -= position->dir_y * MOVE_SPEED;
}

void	move_left(void)
{
	const char	not_wall[5] = "0NEWS";
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(not_wall, info->map \
	[(int)(position->pos_x + position->dir_y * MOVE_SPEED +0.01)] \
	[(int)position->pos_y]))
		position->pos_x += position->dir_y * MOVE_SPEED;
	if (ft_strchr(not_wall, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y - position->dir_x * MOVE_SPEED -0.01)]))
		position->pos_y -= position->dir_x * MOVE_SPEED;
}

void	move_right(void)
{
	const char	not_wall[5] = "0NEWS";
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(not_wall, info->map \
	[(int)(position->pos_x - position->dir_y * MOVE_SPEED -0.01)] \
	[(int)position->pos_y]))
		position->pos_x -= position->dir_y * MOVE_SPEED;
	if (ft_strchr(not_wall, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y + position->dir_x * MOVE_SPEED +0.01)]))
		position->pos_y += position->dir_x * MOVE_SPEED;
}
