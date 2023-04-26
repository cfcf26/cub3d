/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_floor_ceiling_colors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:54:34 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/25 13:34:01 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	is_valid_color(char *color)
{
	int	i;

	i = -1;
	while (color[++i] && color[i] != '\n')
	{
		if (!ft_isdigit(color[i]))
			parse_error(" Wrong floor or ceiling color (4)");
	}
}

static void	free_color(char **color)
{
	int	i;

	i = -1;
	while (color[++i])
		free(color[i]);
	free(color);
}

static void	validate_color(char *line)
{
	char	**color;
	int		rgb[3];

	color = ft_split(line, ',');
	if (!color || !color[0] || !color[1] || !color[2])
		parse_error(" Wrong floor or ceiling color (2)");
	is_valid_color(color[0]);
	rgb[0] = ft_atoi(color[0]);
	is_valid_color(color[1]);
	rgb[1] = ft_atoi(color[1]);
	is_valid_color(color[2]);
	rgb[2] = ft_atoi(color[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 \
	|| rgb[2] < 0 || rgb[2] > 255)
		parse_error(" Wrong floor or ceiling color (3)");
	free_color(color);
}

void	validate_floor_ceiling_colors(int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	line = pass_newline(fd);
	while (flag != 3)
	{
		if (!line)
			parse_error(" Ceiling or floor color is empty");
		if (line && line[0] != '\n')
		{
			if (line[0] == 'F' && !(flag & 1))
				flag |= 1;
			else if (line[0] == 'C' && !(flag & 2))
				flag |= 2;
			else
				parse_error(" Wrong floor or ceiling color (1)");
			validate_color(line + 2);
		}
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	free(line);
}
