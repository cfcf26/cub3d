/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:03:13 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/24 15:32:13 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	remove_newline(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
	}
}

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
		remove_newline(line);
		map[i] = line;
		line = exit_on_get_next_line_failure(fd);
	}
	get_info()->map = map;
}
