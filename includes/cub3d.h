/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:15:49 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 19:22:38 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utils.h"
# include "parser.h"
# include "mlx_utils.h"
# include "position.h"
# include "raycasting.h"

void	turn_right(t_position *position);
void	turn_left(t_position *position);
int		main_loop(t_cub3d *cub3d);
int		key_press(int key, t_cub3d *cub3d);
int		red_button(t_cub3d *cub3d);
#endif