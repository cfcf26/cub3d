/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_paths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:52:30 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 01:34:01 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	validate_texture_file(char *line)
{
	int			open_f;
	const int	len = ft_strlen(line);

	line[len - 1] = '\0';
	validate_file_extension(line, ".xpm");
	open_f = open(line, O_RDONLY);
	if (open_f == -1)
		ft_error("Error : Texture file open failed (1)\n");
	close(open_f);
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
			ft_error("Error : Wrong texture path (1)\n");
		validate_texture_file(line + 3);
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	free(line);
}
