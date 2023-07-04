/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:17:42 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:09:28 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

/**
 * @brief rotate left
 * 
 * @details rotate left
 * 
 */
void	rotate_left(void)
{
	t_position	*position;
	double		old_dir_x;
	double		old_plane_x;

	position = get_position();
	old_dir_x = position->dir_x;
	position->dir_x = \
	position->dir_x * cos(-ROT_SPEED) - position->dir_y * sin(-ROT_SPEED);
	position->dir_y = \
	old_dir_x * sin(-ROT_SPEED) + position->dir_y * cos(-ROT_SPEED);
	old_plane_x = position->plane_x;
	position->plane_x = \
	position->plane_x * cos(-ROT_SPEED) - position->plane_y * sin(-ROT_SPEED);
	position->plane_y = \
	old_plane_x * sin(-ROT_SPEED) + position->plane_y * cos(-ROT_SPEED);
}

/**
 * @brief rotate right
 * 
 * @details rotate right
 * 
 */
void	rotate_right(void)
{
	t_position	*position;
	double		old_dir_x;
	double		old_plane_x;

	position = get_position();
	old_dir_x = position->dir_x;
	position->dir_x = \
	position->dir_x * cos(ROT_SPEED) - position->dir_y * sin(ROT_SPEED);
	position->dir_y = \
	old_dir_x * sin(ROT_SPEED) + position->dir_y * cos(ROT_SPEED);
	old_plane_x = position->plane_x;
	position->plane_x = \
	position->plane_x * cos(ROT_SPEED) - position->plane_y * sin(ROT_SPEED);
	position->plane_y = \
	old_plane_x * sin(ROT_SPEED) + position->plane_y * cos(ROT_SPEED);
}
