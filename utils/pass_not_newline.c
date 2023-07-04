/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_not_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:59:08 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:13:57 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief pass not newline
 * 
 * @details this function is used to pass the lines until the first newline
 * @param fd 
 * @return char* 
 */
char	*pass_not_newline(int fd)
{
	char	*line;

	line = exit_on_get_next_line_failure(fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	if (!line)
		ft_error(" Memory allocation failed (2)");
	return (line);
}
