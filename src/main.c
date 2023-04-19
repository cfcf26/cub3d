/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:30:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 19:49:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	parser(argc, argv);
	init_mlx_struct();
	init_cub3d_struct();
	test_printf("test");
	test_print_info();
	load_texture();
	mlx_loop_hook(get_mlx()->mlx, &main_loop, &cub3d);
	mlx_hook(get_mlx()->win, X_EVENT_KEY_PRESS, 0, &key_press, &cub3d);
	mlx_hook(get_mlx()->win, RED_BUTTON, 0, &red_button, &cub3d);
	mlx_loop(get_mlx()->mlx);
	return (0);
}
