/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_floor_ceiling_colors.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:54:34 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 11:42:23 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	validate_color(char *line)
{
	char	**color;
	int		rgb[3];

	color = ft_split(line, ',');
	if (!color || !color[0] || !color[1] || !color[2])
		write_err("Error : Wrong floor or ceiling color (2)\n");
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 \
	|| rgb[2] < 0 || rgb[2] > 255)
		write_err("Error : Wrong floor or ceiling color (3)\n");
	free(color[0]);
	free(color[1]);
	free(color[2]);
	free(color);
}

void	validate_floor_ceiling_colors(int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	line = pass_newline(fd);
	printf("line: %s\n", line);
	while (flag != 3)
	{
		if (line && line[0] != '\n')
		{
			if (line[0] == 'F' && !(flag & 1))
				flag |= 1;
			else if (line[0] == 'C' && !(flag & 2))
				flag |= 2;
			else
				write_err("Error : Wrong floor or ceiling color (1)\n");
			validate_color(line + 2);
		}
		free(line);
		line = get_next_line(fd);
	}
}