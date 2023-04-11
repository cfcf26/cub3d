/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_before_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:27:40 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 22:31:01 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	pass_before_map(int fd)
{
	char	*line;

	line = pass_newline(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = pass_newline(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
}
