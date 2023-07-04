/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:23:04 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:11:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief check empty line
 * 
 * @details check empty line
 * 
 * @param line 
 */
void	check_empty_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("\n ", line[i]) == NULL)
			return ;
	}
	if (line[i] == '\0')
		parse_error(" Map in this format is not supported.");
}
