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
	const char	set[10] = "012NSEW \n";
	char		*line;
	char		*player;
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
			player = ft_strchr(set, line[i]);
			if (!player && player_count > 1)
				write_err("Error : Wrong character in map (1)\n");
			if (player[0] == 'N' || player[0] == 'S' \
			|| player[0] == 'E' || player[0] == 'W')
				player_count++;
		}
		free(line);
		line = get_next_line(fd);
	}
}
