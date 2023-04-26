/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:14:21 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/26 19:24:06 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

void	move_forward(void)
{
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(NOT_WALL, info->map \
	[(int)(position->pos_x + position->dir_x * MOV)] \
	[(int)position->pos_y]))
		position->pos_x += position->dir_x * MOV;
	if (ft_strchr(NOT_WALL, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y + position->dir_y * MOV)]))
		position->pos_y += position->dir_y * MOV;
}

void	move_backward(void)
{
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(NOT_WALL, info->map \
	[(int)(position->pos_x - position->dir_x * MOV)] \
	[(int)position->pos_y]))
		position->pos_x -= position->dir_x * MOV;
	if (ft_strchr(NOT_WALL, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y - position->dir_y * MOV)]))
		position->pos_y -= position->dir_y * MOV;
}

void	move_left(void)
{
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(NOT_WALL, info->map \
	[(int)(position->pos_x + position->dir_y * MOV)] \
	[(int)position->pos_y]))
		position->pos_x += position->dir_y * MOV;
	if (ft_strchr(NOT_WALL, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y - position->dir_x * MOV)]))
		position->pos_y -= position->dir_x * MOV;
}

void	move_right(void)
{
	t_position	*position;
	t_info		*info;

	position = get_position();
	info = get_info();
	if (ft_strchr(NOT_WALL, info->map \
	[(int)(position->pos_x - position->dir_y * MOV)] \
	[(int)position->pos_y]))
		position->pos_x -= position->dir_y * MOV;
	if (ft_strchr(NOT_WALL, info->map \
	[(int)position->pos_x] \
	[(int)(position->pos_y + position->dir_x * MOV)]))
		position->pos_y += position->dir_x * MOV;
}
