/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_not_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:59:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/24 15:52:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*pass_not_newline(int fd)
{
	char	*line;

	line = exit_on_get_next_line_failure(fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	if (!line)
		ft_error(" Memory allocation failed (2)");
	return (line);
}
