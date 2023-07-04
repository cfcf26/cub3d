/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:00:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:05:52 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief update ray
 * 
 * @details update ray
 * 
 * @param ray 
 */
static void	update_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

/**
 * @brief check if ray hit wall
 * 
 * @details check if ray hit wall
 * 
 * @param ray 
 */
static void	check_hit(t_ray *ray)
{
	const t_info	*info = get_info();

	if (ray->map_x < 0 || ray->map_x >= info->height || \
		ray->map_y < 0 || ray->map_y >= info->width[ray->map_x])
	{
		ray->hit = 1;
		ray->map_x -= ray->step_x;
		ray->map_y -= ray->step_y;
	}
	if (info->map[ray->map_x][ray->map_y] == '1')
		ray->hit = 1;
}

/**
 * @brief calculate distance from player to wall
 * 
 * @details calculate distance from player to wall
 * 
 * @param ray 
 */
void	calc_dda(t_ray *ray)
{
	while (ray->hit == 0)
	{
		update_ray(ray);
		check_hit(ray);
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
