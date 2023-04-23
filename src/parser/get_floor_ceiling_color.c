/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:02:14 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/23 15:06:28 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	get_color(char **f_color, char **c_color)
{
	get_info()->floor[0] = ft_atoi(f_color[0]);
	get_info()->floor[1] = ft_atoi(f_color[1]);
	get_info()->floor[2] = ft_atoi(f_color[2]);
	get_info()->ceiling[0] = ft_atoi(c_color[0]);
	get_info()->ceiling[1] = ft_atoi(c_color[1]);
	get_info()->ceiling[2] = ft_atoi(c_color[2]);
	free_split(f_color);
	free_split(c_color);
}

void	get_floor_ceiling_color(int fd)
{
	char	*line_1;
	char	*line_2;

	line_1 = pass_newline(fd);
	line_2 = exit_on_get_next_line_failure(fd);
	if (line_1[0] == 'F')
		get_color(ft_split(line_1 + 2, ','), ft_split(line_2 + 2, ','));
	else
		get_color(ft_split(line_2 + 2, ','), ft_split(line_1 + 2, ','));
	free(line_1);
	free(line_2);
}
