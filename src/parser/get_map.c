/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:03:13 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 01:33:40 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_map(int fd)
{
	char	*line;
	char	**map;
	int		i;

	line = pass_newline(fd);
	map = exit_on_calloc_failure(get_info()->height + 1, sizeof(char *));
	i = -1;
	while (++i < get_info()->height)
	{
		if (line[get_info()->width[i] - 1] == '\n')
			line[get_info()->width[i] - 1] = '\0';
		map[i] = line;
		line = exit_on_get_next_line_failure(fd);
	}
	get_info()->map = map;
}
