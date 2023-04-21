/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:53:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 01:34:11 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*pass_newline(int fd)
{
	char	*line;

	line = exit_on_get_next_line_failure(fd);
	while (line)
	{
		if (line[0] != '\n')
			break ;
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	if (!line)
		ft_error("Error : Memory allocation failed (1)\n");
	return (line);
}
