/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:46:12 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:14:25 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief validate file extension
 * 
 * @details validate file extension
 * 
 * @param file_name 
 * @param extension 
 */
void	validate_file_extension(char *file_name, char *extension)
{
	const int	i = ft_strlen(file_name);
	const int	j = ft_strlen(extension);

	if (i <= j)
		parse_error(" File name is too short (1)");
	if (ft_strncmp(file_name + i - j, extension, j))
		parse_error(" Wrong file extension (1)");
}
