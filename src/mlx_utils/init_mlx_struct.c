/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:10:15 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 02:54:12 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

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

static void	get_data_addr(t_img *texture, void *img)
{
	int	*data;
	int	i;

	texture->data = exit_on_malloc_failure(sizeof(int) * TILE_SIZE * TILE_SIZE);
	data = (int *)mlx_get_data_addr(img, \
						&texture->bpp, &texture->size_line, &texture->endian);
	if (data == NULL)
		ft_error("Error : Mlx texture init failed (2)");
	i = -1;
	while (++i < TILE_SIZE * TILE_SIZE)
		texture->data[i] = data[i];
}

static void	check_image(t_img *texture, void *img)
{
	if (texture->width != TILE_SIZE || texture->height != TILE_SIZE)
		ft_error("Error : Mlx texture size is not 64x64 (1)");
	if (img == NULL)
		ft_error("Error : Mlx texture init failed (1)");
}

static void	get_texture(t_img *texture, char *path, void *mlx)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	check_image(texture, img);
	get_data_addr(texture, img);
	mlx_destroy_image(mlx, img);
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
	get_texture(&mlx->texture[0], info->no, mlx->mlx);
	get_texture(&mlx->texture[1], info->so, mlx->mlx);
	get_texture(&mlx->texture[2], info->we, mlx->mlx);
	get_texture(&mlx->texture[3], info->ea, mlx->mlx);
	init_buffer(mlx);
	mlx->re_buf = 0;
	return (mlx);
}
