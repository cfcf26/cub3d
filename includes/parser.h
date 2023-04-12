/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:31:12 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/13 02:10:42 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"

# define VALID_MAP_CHAR "012NSEW "
# define VALID_PLAYER_CHAR "NSEW"

void	parser(int ac, char **av);
/*void	validate_file_contents(int ac, char **av);*/
void	validate_file(int ac, char **av);
void	validate_texture_paths(int fd);
void	validate_floor_ceiling_colors(int fd);
void	validate_map_characters(int fd);
/*void	get_info_from_file(char *file_name);*/
void	get_map_size(char *file_name);
void	get_texture_paths(int fd);
void	get_floor_ceiling_color(int fd);
void	get_map(int fd);

void	validate_map_walls(void);
#endif
