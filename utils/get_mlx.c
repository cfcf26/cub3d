/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:13:46 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/16 18:54:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	validate_mlx_init(t_mlx *mlx)
{
	if (mlx->north == NULL)
		ft_error("Error : Mlx north texture init failed (1)");
	if (mlx->south == NULL)
		ft_error("Error : Mlx south texture init failed (1)");
	if (mlx->west == NULL)
		ft_error("Error : Mlx west texture init failed (1)");
	if (mlx->east == NULL)
		ft_error("Error : Mlx east texture init failed (1)");
}

static t_mlx	*init_mlx_struct(void)
{
	const t_info	*info = get_info();
	t_mlx			*mlx;
	int				width;
	int				height;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_error("Error : Mlx init failed (1)");
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (mlx->win == NULL)
		ft_error("Error : Mlx window init failed (1)");
	mlx->north = mlx_xpm_file_to_image(mlx->mlx, info->no, &width, &height);
	mlx->south = mlx_xpm_file_to_image(mlx->mlx, info->so, &width, &height);
	mlx->west = mlx_xpm_file_to_image(mlx->mlx, info->we, &width, &height);
	mlx->east = mlx_xpm_file_to_image(mlx->mlx, info->ea, &width, &height);
	return (mlx);
}

t_mlx	*get_mlx(void)
{
	static t_mlx	*mlx;

	if (mlx == NULL)
	{
		mlx = init_mlx_struct();
		validate_mlx_init(mlx);
	}
	return (mlx);
}
