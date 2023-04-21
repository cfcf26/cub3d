/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:41:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 02:55:14 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	validate_map_characters(int fd)
{
	char		*line;
	int			player_count;
	int			i;

	line = pass_newline(fd);
	if (!line)
		parse_error("Error : Map is empty (1)");
	player_count = 0;
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (!(ft_strchr(VALID_MAP_CHAR, line[i])) && player_count > 1)
				parse_error("Error : Too many players (1)");
			if (line[i] == 'N' || line[i] == 'S' \
			|| line[i] == 'E' || line[i] == 'W')
				player_count++;
		}
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	if (player_count != 1)
		parse_error("Error : No player (1)");
	free(line);
}
