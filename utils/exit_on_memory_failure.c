/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_on_memory_failure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:47:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 01:34:06 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*exit_on_malloc_failure(size_t s)
{
	void	*dynamic_array;

	dynamic_array = malloc(s);
	if (dynamic_array == NULL || errno == ENOMEM)
		ft_error("Error : Memory allocation error");
	return (dynamic_array);
}

void	*exit_on_calloc_failure(size_t nmemb, size_t size)
{
	void	*dynamic_array;

	dynamic_array = ft_calloc(nmemb, size);
	if (dynamic_array == NULL || errno == ENOMEM)
		ft_error("Error : Memory allocation error");
	return (dynamic_array);
}

char	*exit_on_get_next_line_failure(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (errno == ENOMEM)
		ft_error("Error : Memory allocation error");
	return (line);
}
