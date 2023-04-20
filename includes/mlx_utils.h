/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:16:14 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 04:12:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "utils.h"

t_mlx	*init_mlx_struct(void);
void	get_texture(t_img *texture, char *path, void *mlx);
void	draw(t_mlx *mlx);

#endif