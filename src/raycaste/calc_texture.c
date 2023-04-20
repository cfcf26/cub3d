/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:58:47 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 03:59:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaste.h"

void	calc_texture(t_draw *draw, t_ray *ray)
{
	double		wall_x;
	t_position	*position;

	position = get_position();
	if (ray->side == 0)
		wall_x = position->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = position->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * (double)TILE_SIZE);
	if (ray->side == 0)
		draw->tex_x = TILE_SIZE - draw->tex_x - 1;
	if (ray->side == 1)
		draw->tex_x = TILE_SIZE - draw->tex_x - 1;
	draw->step = 1.0 * TILE_SIZE / draw->line_height;
	draw->tex_pos = \
	(draw->draw_start - WIN_HEIGHT / 2 + draw->line_height / 2) * draw->step;
	if (ray->side == 0 && ray->dir_x < 0)
		draw->tex_num = 0;
	else if (ray->side == 0 && ray->dir_x >= 0)
		draw->tex_num = 1;
	else if (ray->side == 1 && ray->dir_y < 0)
		draw->tex_num = 2;
	else if (ray->side == 1 && ray->dir_y >= 0)
		draw->tex_num = 3;
}
