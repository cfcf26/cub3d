/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readme.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:37:04 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 02:56:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef README_H
# define README_H

# define CONTENTS "This program is a mentor program in the Cub3D assignment \
and accepts files with the following rules.\n 1. The map must be composed of \
only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W \
for the player's start position and spawning.\n 2. The map must be \
closed/surrounded by walls.\n 3. Except for the map content, \
each type of element can be separated by one or more empty line(s). \
- This instruction is controversial, so according to the developer's \
arbitrary interpretation, the file must consist of 3 elements, \
and according to the instruction, there may be one or more empty lines \
between each element. Otherwise, the program will not work if the order of \
the elements is different, or if there are spaces between elements.\n \
The order within a single element may vary according to the instructions \
(Except for the map content which always has to be the last, each type of \
element can be set in any order in the file.)\n \
4. there is no instruction for the texture file, so it must be a .xpm file \
with a size of 64 * 64, according to the developer's arbitrary interpretation.\
\n\n \
Below is a description of each element.\n\n \
The first element is textures,\n \
NO,SO,WE,EA, respectively, and the filename must be written with one space. \n \
Ex) NO ./path_to_the_north_texture\n \
The second element is the floor and ceiling color,\n \
It consists of three values between R,G,B values (0. 255), \
starting with F,C respectively, with one space.\n \
Ex) F 220,100,0\n \
The third element is a map, which can be written freely according to \
the example and rules.\n \
Ex)\n \
111111\n \
100101\n \
101001\n \
1100N1\n \
111111\n \
"
#endif
