/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:30:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 04:21:47 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reset_buf(t_mlx *mlx)
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

static int	main_loop(void)
{
	calculation();
	draw(get_mlx());
	reset_buf(get_mlx());
	return (0);
}

int	main(int argc, char **argv)
{
	parser(argc, argv);
	init_mlx_struct();
	get_position_from_info();
	mlx_loop_hook(get_mlx()->mlx, &main_loop, 0);
	mlx_hook(get_mlx()->win, X_EVENT_KEY_PRESS, 0, &key_press, 0);
	mlx_loop(get_mlx()->mlx);
	test_printf("test");
	test_print_info();
	return (0);
}
