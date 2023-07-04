/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:52:51 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:08:32 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief validate file extension
 * 
 * @details validate file extension
 * 
 * @param file_name 
 * @param extension 
 */
static void	validate_file_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		parse_error(" File open failed (1)");
	close(fd);
}

/**
 * @brief validate file extension
 * 
 * @details validate file extension
 * 
 * @param file_name 
 * @param extension 
 */
static void	validate_arguments(int ac)
{
	if (ac != 2)
		parse_error(" Wrong number of arguments (1)");
}

/**
 * @brief validate file
 * 
 * @details validate file
 * 
 * @param ac 
 * @param av 
 */
void	validate_file(int ac, char **av)
{
	validate_arguments(ac);
	validate_file_extension(av[1], ".cub");
	validate_file_open(av[1]);
}
