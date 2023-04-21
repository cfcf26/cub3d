/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:09:51 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 02:57:03 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "readme.h"

static void	create_readme_file(void)
{
	int			fd;

	fd = open("README.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_error("Error : creating README file");
	if (write(fd, CONTENTS, ft_strlen(CONTENTS)) == -1)
		ft_error("Error : writing to README file");
	close(fd);
}

void	parse_error(const char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	create_readme_file();
	ft_error("Error : input file is not valid please check README.txt");
}
