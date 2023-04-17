/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:40:33 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 18:02:51 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "utils.h"

void	init_ray(t_ray *ray, t_position *position, int x);
void	calc_step_and_side_dist(t_ray *ray, t_position *position);
void	perform_dda(t_ray *ray, t_info *info);
void	calc_wall_distance_and_line_height(t_ray *ray, t_position *position);
void	calc_draw_start_and_end(t_ray *ray);

#endif