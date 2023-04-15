/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:03:13 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:04:55 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_map(int fd)
{
	const char	spawn[4] = "NEWS";
	char		*line;
	char		**map;
	int			i;

	line = pass_newline(fd);
	map = ft_calloc(get_info()->height + 1, sizeof(char *));
	i = -1;
	while (++i < get_info()->height)
	{
		if (ft_strchr(spawn, line[get_info()->width[i]]))
			get_info()->player_spawn;
		if (line[get_info()->width[i] - 1] == '\n')
			line[get_info()->width[i] - 1] = '\0';
		map[i] = line;
		line = get_next_line(fd);
	}
	get_info()->map = map;
}
