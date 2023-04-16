/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_not_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:59:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/16 18:54:54 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*pass_not_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		ft_error("Error : Memory allocation failed (2)\n");
	return (line);
}
