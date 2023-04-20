/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaste.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:40:33 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 04:01:33 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTE_H
# define RAYCASTE_H

# include "utils.h"

void	init_ray(t_ray *ray, const t_position *position, int x);
void	calculation(void);
void	draw_wall(t_draw *draw, t_ray *ray, t_mlx *mlx, int x);
void	calc_texture(t_draw *draw, t_ray *ray);
void	calc_draw_start_and_end(t_draw *draw, t_ray *ray);
void	calc_dda(t_ray *ray);
void	calc_step_and_side_dist(t_ray *ray, const t_position *position);

#endif