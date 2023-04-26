/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 04:14:33 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/26 19:27:24 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "utils.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define RED_BUTTON 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define MOV 0.49
# define ROT_SPEED 0.05

int		key_press(int keycode);

void	rotate_left(void);
void	rotate_right(void);

void	move_forward(void);
void	move_backward(void);
void	move_left(void);
void	move_right(void);

int		exit_game(void);
#endif
