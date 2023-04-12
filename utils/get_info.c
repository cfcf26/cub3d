/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:58:59 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:19:31 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_info	*get_info(void)
{
	static t_info	*info = NULL;

	if (info == NULL)
	{
		info = ft_calloc(1, sizeof(t_info));
		return (info);
	}
	else
		return (info);
}
