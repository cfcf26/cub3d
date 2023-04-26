/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:41:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/25 13:32:18 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_valid_map_char(char c)
{
	return (ft_strchr(VALID_MAP_CHAR, c) != NULL);
}

static void	check_map_characters(const char *line, int *player_count)
{
	while (*line)
	{
		if (!is_valid_map_char(*line))
			parse_error(" Invalid character in map (1)");
		if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			(*player_count)++;
		line++;
	}
}

void	validate_map_characters(int fd)
{
	char	*line;
	int		player_count;

	line = pass_newline(fd);
	if (!line)
		parse_error(" Map is empty (1)");
	player_count = 0;
	while (line)
	{
		check_empty_line(line);
		check_map_characters(line, &player_count);
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	if (player_count <= 0)
		parse_error(" No player (1)");
	else if (player_count > 1)
		parse_error(" Too many players (1)");
	free(line);
}
