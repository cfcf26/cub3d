/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:41:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 21:37:00 by ekwak            ###   ########.fr       */
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
		write_err("Error : Map is empty (1)\n");
	player_count = 0;
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (!(ft_strchr(VALID_MAP_CHAR, line[i])) && player_count > 1)
				write_err("Error : Too many players (1)\n");
			if (line[i] == 'N' || line[i] == 'S' \
			|| line[i] == 'E' || line[i] == 'W')
				player_count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (player_count != 1)
		write_err("Error : No player (1)\n");
	free(line);
}
