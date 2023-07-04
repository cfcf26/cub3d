/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:53:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:12:49 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief pass newline
 * 
 * @details pass newline
 * 
 * @param fd 
 * @return char* 
 */
char	*pass_newline(int fd)
{
	char	*line;

	line = exit_on_get_next_line_failure(fd);
	while (line)
	{
		if (line[0] != '\n')
			break ;
		free(line);
		line = exit_on_get_next_line_failure(fd);
	}
	if (errno == ENOMEM)
		ft_error(" Memory allocation failed (1)");
	return (line);
}
