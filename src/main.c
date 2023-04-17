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
	test_printf("test");
	test_print_info();
	return (0);
}
