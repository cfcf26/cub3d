/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:08:07 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/14 01:47:35 by ekwak            ###   ########.fr       */
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
# include "models.h" // models

# ifdef DEBUG_MODE

void	test_printf(char *str);
void	test_print_info(void);
# endif

# ifndef DEBUG_MODE

void	test_printf(char *str);
void	test_print_info(void);
# endif

void	validate_file_extension(char *file_name, char *extension);
void	write_err(char *str);
char	*pass_newline(int fd);
char	*pass_not_newline(int fd);
t_info	*get_info(void);
t_mlx	*get_mlx(void);
#endif
