/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:46:12 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/14 01:50:03 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	validate_file_extension(char *file_name, char *extension)
{
	const int	i = ft_strlen(file_name);
	const int	j = ft_strlen(extension);

	if (i <= j)
		write_err("Error : File name is too short (1)\n");
	if (ft_strncmp(file_name + i - j, extension, j))
		write_err("Error : Wrong file extension (1)\n");
}
