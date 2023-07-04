/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:58:59 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:12:27 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief get info
 * 
 * @details get info
 * 
 * @return t_info* 
 */
t_info	*get_info(void)
{
	static t_info	info;

	return (&info);
}
