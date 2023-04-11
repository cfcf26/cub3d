/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:08:07 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 12:25:28 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h> // printf
# include <math.h> //
# include <stdlib.h> // malloc, free
# include <unistd.h> // read, write, close
# include <fcntl.h> // open
# include "../minilibx_opengl_20191021/mlx.h" // mlx
# include "../libft/libft.h" // libft

# ifdef DEBUG_MODE

void	test_printf(char *str);
# endif

void	write_err(char *str);
char	*pass_newline(int fd);
#endif