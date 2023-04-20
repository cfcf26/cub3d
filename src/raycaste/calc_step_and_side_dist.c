/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_step_and_side_dist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:58:03 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 04:01:35 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaste.h"

void	calc_step_and_side_dist(t_ray *ray, const t_position *position)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (position->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = \
		(ray->map_x + 1.0 - position->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (position->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = \
		(ray->map_y + 1.0 - position->pos_y) * ray->delta_dist_y;
	}
}
