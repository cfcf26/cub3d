/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:29:06 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:12:35 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief get position
 * 
 * @details get position
 * 
 * @return t_position* 
 */
t_position	*get_position(void)
{
	static t_position	position;

	return (&position);
}
