/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:16:14 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/26 19:37:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "utils.h"

t_mlx	*init_graphics_context(void);
void	get_texture(t_img *texture, char *path, void *mlx);
void	draw(t_mlx *mlx);
void	synchronize_direction(t_mlx *mlx);
void	draw_floor_ceiling(t_mlx *mlx, t_info *info);
void	reset_buf(t_mlx *mlx);
#endif
