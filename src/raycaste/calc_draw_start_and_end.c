/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_draw_start_and_end.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:00:03 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:06:02 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief calculate draw start and end
 * 
 * @details calculate draw start and end
 * 
 * @param draw 
 * @param ray 
 */
void	calc_draw_start_and_end(t_draw *draw, t_ray *ray)
{
	draw->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
}
