/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:16:50 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/23 16:04:41 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	exit_game(void)
{
	exit(0);
}

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		move_forward();
	if (keycode == KEY_S)
		move_backward();
	if (keycode == KEY_A)
		move_left();
	if (keycode == KEY_D)
		move_right();
	if (keycode == KEY_LEFT)
		rotate_left();
	if (keycode == KEY_RIGHT)
		rotate_right();
	return (0);
}
