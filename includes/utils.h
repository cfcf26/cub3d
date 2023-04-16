/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:08:07 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/16 19:13:02 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h> // printf
# include <math.h> //
# include <stdlib.h> // malloc, free
# include <unistd.h> // read, write, close
# include <fcntl.h> // open
# include <errno.h> // errno
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

void	ft_error(char *str);
void	*exit_on_malloc_failure(size_t s);
void	*exit_on_calloc_failure(size_t nmemb, size_t size);
char	*exit_on_get_next_line_failure(int fd);

char	*pass_newline(int fd);
char	*pass_not_newline(int fd);

t_info	*get_info(void);
t_mlx	*get_mlx(void);

void	validate_file_extension(char *file_name, char *extension);
#endif
