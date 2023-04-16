/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:53:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/16 18:54:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*pass_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		ft_error("Error : Memory allocation failed (1)\n");
	return (line);
}
