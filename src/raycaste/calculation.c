/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:47:22 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:42:23 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief calculate
 * 
 * @details calculate raycast and draw wall on the screen
 * 
 */
void	calculation(void)
{
	int					x;
	t_ray				ray;
	t_draw				draw;
	const t_position	*position = get_position();

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, position, x);
		calc_step_and_side_dist(&ray, position);
		calc_dda(&ray);
		calc_draw_start_and_end(&draw, &ray);
		calc_texture(&draw, &ray);
		draw_wall(&draw, &ray, get_mlx(), x);
		x++;
	}
}
