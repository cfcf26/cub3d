/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:03:38 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:11:32 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

/**
 * @brief reset buf
 * 
 * @details reset buf
 * 
 * @param mlx 
 */
void	reset_buf(t_mlx *mlx)
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
