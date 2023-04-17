/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:17 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 18:07:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_ray(t_ray *ray, t_position *position, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = position->dir_x + position->plane_x * ray->camera_x;
	ray->ray_dir_y = position->dir_y + position->plane_y * ray->camera_x;
	ray->map_x = (int)position->pos_x;
	ray->map_y = (int)position->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}