/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:30:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/24 16:09:55 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	main_loop(void)
{
	draw_floor_ceiling(get_mlx(), get_info());
	calculation();
	draw(get_mlx());
	reset_buf(get_mlx());
	return (0);
}

static void	routines(void)
{
	void	*mlx;
	void	*win;

	mlx = get_mlx()->mlx;
	win = get_mlx()->win;
	mlx_loop_hook(mlx, &main_loop, 0);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, 0);
	mlx_hook(win, X_EVENT_KEY_EXIT, 0, &exit_game, 0);
	mlx_loop(mlx);
}

static void	setup(void)
{
	get_position_from_info();
	init_graphics_context();
}

int	main(int argc, char **argv)
{
	parser(argc, argv);
	setup();
	routines();
	return (0);
}
