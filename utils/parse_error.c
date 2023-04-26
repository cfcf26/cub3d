/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:09:51 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/25 13:26:33 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "readme.h"

static void	create_readme_file(void)
{
	int			fd;

	fd = open("README.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_error(" creating README file");
	if (write(fd, CONTENTS, ft_strlen(CONTENTS)) == -1)
		ft_error(" writing to README file");
	close(fd);
}

void	parse_error(const char *err_msg)
{
	write(2, "Error\n", 6);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	create_readme_file();
	write(2, " input file is not valid please check README.txt\n", 49);
	exit(EXIT_FAILURE);
}
