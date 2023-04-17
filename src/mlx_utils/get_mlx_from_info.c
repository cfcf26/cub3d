/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx_from_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:10:15 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 17:16:46 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	check_image(int width, int height, void *img)
{
	if (width != TILE_SIZE || height != TILE_SIZE)
		write_err("Error : Mlx texture size is not 64x64 (1)");
	if (img == NULL)
		write_err("Error : Mlx texture init failed (1)");
}

t_mlx	*init_mlx_struct(void)
{
	const t_info	*info = get_info();
	t_mlx			*mlx;
	int				width;
	int				height;

	mlx = get_mlx();
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_error("Error : Mlx init failed (1)");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (mlx->win == NULL)
		ft_error("Error : Mlx window init failed (1)");
	mlx->north = mlx_xpm_file_to_image(mlx->mlx, info->no, &width, &height);
	check_image_size(width, height, mlx->north);
	mlx->south = mlx_xpm_file_to_image(mlx->mlx, info->so, &width, &height);
	check_image_size(width, height, mlx->south);
	mlx->west = mlx_xpm_file_to_image(mlx->mlx, info->we, &width, &height);
	check_image_size(width, height, mlx->west);
	mlx->east = mlx_xpm_file_to_image(mlx->mlx, info->ea, &width, &height);
	check_image_size(width, height, mlx->east);
	return (mlx);
}
