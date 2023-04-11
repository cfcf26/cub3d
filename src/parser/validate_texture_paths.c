/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_paths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:52:30 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 11:55:31 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	validate_paths(char *line)
{
	int			open_f;
	const int	len = ft_strlen(line);

	line[len - 1] = '\0';
	open_f = open(line, O_RDONLY);
	if (open_f == -1)
		write_err("Error : Texture file open failed (1)\n");
	close(open_f);
	free(line);
}

void	validate_texture_paths(int fd)
{
	int		flag;
	char	*line;

	flag = 0;
	line = pass_newline(fd);
	while (flag != 15)
	{
		if (line && line[0] == 'N' && line[1] == 'O' && !(flag & 1))
			flag |= 1;
		else if (line && line[0] == 'S' && line[1] == 'O' && !(flag & 2))
			flag |= 2;
		else if (line && line[0] == 'W' && line[1] == 'E' && !(flag & 4))
			flag |= 4;
		else if (line && line[0] == 'E' && line[1] == 'A' && !(flag & 8))
			flag |= 8;
		else
			write_err("Error : Wrong texture path (1)\n");
		validate_paths(ft_strdup(line + 3));
		free(line);
		line = get_next_line(fd);
	}
}
