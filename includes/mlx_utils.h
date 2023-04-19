/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:16:14 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 17:16:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "utils.h"

t_mlx	*init_mlx_struct(void);
t_cub3d	*init_cub3d_struct(void);
void	init_imagine(void);
#endif