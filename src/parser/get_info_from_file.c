/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:58:41 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:03:33 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_info_from_file(char *file_name)
{
	int	fd;

	get_info()->file_name = file_name;
	get_map_size(file_name);
	fd = open(file_name, O_RDONLY);
	get_texture_paths(fd);
	get_floor_ceiling_color(fd);
	get_map(fd);
	close(fd);
}
