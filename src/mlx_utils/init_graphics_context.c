/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics_context.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:10:15 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/26 19:40:38 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	init_canvas(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	mlx->canvas.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->canvas.data = (int *)mlx_get_data_addr(mlx->canvas.img, \
						&mlx->canvas.bpp, &mlx->canvas.size_line, \
						&mlx->canvas.endian);
}

static void	init_buffer(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			mlx->buf[i][j] = 0;
	}
}

t_mlx	*init_graphics_context(void)
{
	const t_info	*info = get_info();
	t_mlx			*mlx;

	mlx = get_mlx();
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_error(" Mlx init failed (1)");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (mlx->win == NULL)
		ft_error(" Mlx window init failed (1)");
	get_texture(&mlx->texture[0], info->we, mlx->mlx);
	get_texture(&mlx->texture[1], info->ea, mlx->mlx);
	get_texture(&mlx->texture[2], info->no, mlx->mlx);
	get_texture(&mlx->texture[3], info->so, mlx->mlx);
	synchronize_direction(mlx);
	init_buffer(mlx);
	init_canvas();
	return (mlx);
}
