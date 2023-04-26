/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:08:12 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/24 15:52:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	get_data_addr(t_img *texture, void *img)
{
	int	*data;
	int	i;

	texture->data = exit_on_malloc_failure(sizeof(int) * TILE_SIZE * TILE_SIZE);
	data = (int *)mlx_get_data_addr(img, \
						&texture->bpp, &texture->size_line, &texture->endian);
	if (data == NULL)
		ft_error(" Mlx texture init failed (2)");
	i = -1;
	while (++i < TILE_SIZE * TILE_SIZE)
		texture->data[i] = data[i];
}

static void	check_image(t_img *texture, void *img)
{
	if (texture->width != TILE_SIZE || texture->height != TILE_SIZE)
		parse_error(" Mlx texture size is not 64x64 (1)");
	if (img == NULL)
		ft_error(" Mlx texture init failed (1)");
}

void	get_texture(t_img *texture, char *path, void *mlx)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	check_image(texture, img);
	get_data_addr(texture, img);
	mlx_destroy_image(mlx, img);
}
