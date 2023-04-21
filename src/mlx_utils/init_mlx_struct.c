/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:10:15 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 01:07:40 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	flip_horizontal_image(t_img *img)
{
	int		i;
	int		j;
	int		temp;
	int		*data;

	data = img->data;
	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width / 2)
		{
			temp = data[i * img->width + j];
			data[i * img->width + j] = data[i * img->width + \
										(img->width - j - 1)];
			data[i * img->width + (img->width - j - 1)] = temp;
		}
	}
}

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

static void	synchronize_direction(t_mlx *mlx, const t_info *info)
{
	if (info->player_char == 'N' || info->player_char == 'S')
	{
		flip_horizontal_image(&mlx->texture[1]);
		flip_horizontal_image(&mlx->texture[2]);
	}
	else if (info->player_char == 'W' || info->player_char == 'E')
	{
		flip_horizontal_image(&mlx->texture[0]);
		flip_horizontal_image(&mlx->texture[3]);
	}
}

t_mlx	*init_mlx_struct(void)
{
	const t_info	*info = get_info();
	t_mlx			*mlx;

	mlx = get_mlx();
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_error("Error : Mlx init failed (1)");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (mlx->win == NULL)
		ft_error("Error : Mlx window init failed (1)");
	get_texture(&mlx->texture[0], info->ea, mlx->mlx);
	get_texture(&mlx->texture[1], info->we, mlx->mlx);
	get_texture(&mlx->texture[2], info->no, mlx->mlx);
	get_texture(&mlx->texture[3], info->so, mlx->mlx);
	synchronize_direction(mlx, info);
	init_buffer(mlx);
	init_canvas();
	return (mlx);
}
