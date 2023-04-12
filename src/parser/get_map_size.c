/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:58:51 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:35:13 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*pass_before_map(int fd)
{
	char	*line;

	line = pass_newline(fd);
	free(line);
	line = pass_not_newline(fd);
	free(line);
	line = pass_newline(fd);
	free(line);
	line = pass_not_newline(fd);
	free(line);
	line = pass_newline(fd);
	return (line);
}

static int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file_name, O_RDONLY);
	line = pass_before_map(fd);
	height = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		height++;
	}
	if (line)
		free(line);
	close(fd);
	return (height);
}

static int	*get_width(char *file_name, int height)
{
	int			fd;
	char		*line;
	int			*width;
	int			i;

	width = ft_calloc(height, sizeof(int));
	fd = open(file_name, O_RDONLY);
	line = pass_before_map(fd);
	i = -1;
	while (++i < height)
	{
		width[i] = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width);
}

void	get_map_size(char *file_name)
{
	int	height;
	int	*width;

	height = get_height(file_name);
	width = get_width(file_name, height);
	get_info()->height = height;
	get_info()->width = width;
}
