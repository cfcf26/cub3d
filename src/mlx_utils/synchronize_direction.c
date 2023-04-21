/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronize_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:22:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 01:23:18 by ekwak            ###   ########.fr       */
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

void	synchronize_direction(t_mlx *mlx, t_position *position)
{
	if (position->player_char == 'N' || position->player_char == 'S')
	{
		flip_horizontal_image(&mlx->texture[1]);
		flip_horizontal_image(&mlx->texture[2]);
	}
	else if (position->player_char == 'W' || position->player_char == 'E')
	{
		flip_horizontal_image(&mlx->texture[0]);
		flip_horizontal_image(&mlx->texture[3]);
	}
}
