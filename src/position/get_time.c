/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:21:43 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 19:44:55 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// double	get_time(void)
// {
// 	struct timeval	tv;
// 	static double	old_time;
// 	double			new_time;
// 	double			time;

// 	gettimeofday(&tv, NULL);
// 	if (old_time == 0)
// 		old_time = (double)tv.tv_sec + (double)tv.tv_usec * 0.000001;
// 	new_time = (double)tv.tv_sec + (double)tv.tv_usec * 0.000001;
// 	time = new_time - old_time;
// 	old_time = new_time;
// 	return (time);
// }
