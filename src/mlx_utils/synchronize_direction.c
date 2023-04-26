/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronize_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:22:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/26 19:37:56 by ekwak            ###   ########.fr       */
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

void	synchronize_direction(t_mlx *mlx)
{
	flip_horizontal_image(&mlx->texture[1]);
	flip_horizontal_image(&mlx->texture[2]);
}
