/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:59:17 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:14:02 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief test print info
 * 
 * @details test print info
 * 
 * @return void
 */
#ifdef DEBUG_MODE

void	test_print_info(void)
{
	t_info	*info;
	int		i;

	info = get_info();
	printf("file_name: %s\n", info->file_name);
	printf("no: %s\n", info->no);
	printf("so: %s\n", info->so);
	printf("we: %s\n", info->we);
	printf("ea: %s\n", info->ea);
	printf("floor: %d %d %d\n", \
	info->floor[0], info->floor[1], info->floor[2]);
	printf("ceiling: %d %d %d\n", \
	info->ceiling[0], info->ceiling[1], info->ceiling[2]);
	printf("height: %d\n", info->height);
	i = -1;
	while (++i < info->height)
		printf("width[%d]: %d\n", i, info->width[i]);
	i = -1;
	printf("map:\n");
	while (info->map[++i])
		printf("%s\n", info->map[i]);
}
#endif

#ifndef DEBUG_MODE

void	test_print_info(void)
{
	(void)1;
}
#endif
