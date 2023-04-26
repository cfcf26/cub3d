/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:23:04 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/25 13:43:46 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
