/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:01:25 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:08:09 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief get texture paths
 * 
 * @details get texture paths
 * 
 * @param fd 
 */
void	get_texture_paths(int fd)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 4)
	{
		line = pass_newline(fd);
		check_empty_line(line);
		line[ft_strlen(line) - 1] = '\0';
		if (line[0] == 'N')
			get_info()->no = ft_strdup(line + 3);
		else if (line[0] == 'S')
			get_info()->so = ft_strdup(line + 3);
		else if (line[0] == 'W')
			get_info()->we = ft_strdup(line + 3);
		else if (line[0] == 'E')
			get_info()->ea = ft_strdup(line + 3);
		free(line);
	}
}
