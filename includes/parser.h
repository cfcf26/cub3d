/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:31:12 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 22:30:54 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"
# include "models.h"

void	pass_before_map(int fd);
int		validate_file(int ac, char **av);
void	validate_floor_ceiling_colors(int fd);
void	validate_texture_paths(int fd);
void	validate_map_characters(int fd);
void	parser(int ac, char **av);

int		check_line_size(char *line);
void	make_map(char *file_name, char ***tmp_map);
char	**make_map2(char *file_name, int size[2]);
void	check_map_size(char *file_name, int size[2]);
void	validate_map_wall(char **tmp_map, int size[2]);
void	validate_map_wall2(char **tmp_map, int size[2]);
#endif
