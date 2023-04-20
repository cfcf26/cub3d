/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:54:47 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 03:57:31 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaste.h"

void	draw_wall(t_draw *draw, t_ray *ray, t_mlx *mlx, int x)
{
	int	y;
	int	color;

	color = 0;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		draw->tex_y = (int)draw->tex_pos & (TILE_SIZE - 1);
		draw->tex_pos += draw->step;
		color = \
		mlx->texture[draw->tex_num].data[TILE_SIZE * draw->tex_y + draw->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		mlx->buf[y][x] = color;
		y++;
	}
}
