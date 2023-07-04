/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:12:21 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:11:05 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

/**
 * @brief draw floor and ceiling
 * 
 * @details draw floor and ceiling
 * 
 * @param mlx 
 * @param info 
 */
void	draw_floor_ceiling(t_mlx *mlx, t_info *info)
{
	const int	floor_color = \
	info->floor[0] << 16 | info->floor[1] << 8 | info->floor[2];
	const int	ceiling_color = \
	info->ceiling[0] << 16 | info->ceiling[1] << 8 | info->ceiling[2];
	int			i;
	int			j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				mlx->buf[i][j] = ceiling_color;
			else
				mlx->buf[i][j] = floor_color;
		}
	}
}

/**
 * @brief draw
 * 
 * @details draw
 * 
 * @param mlx 
 */
void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx->canvas.data[y * WIN_WIDTH + x] = mlx->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->canvas.img, 0, 0);
}
