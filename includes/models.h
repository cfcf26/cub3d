/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:39:48 by ekwak             #+#    #+#             */
/*   Updated: 2023/07/04 12:16:30 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file models.h
 * @brief models header file
 * @details models header file
 */
#ifndef MODELS_H
# define MODELS_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64
# define VALID_MAP_CHAR "01NSEW \n"
# define VALID_PLAYER_CHAR "NSEW"
# define NOT_WALL "0NEWS"

/**
 * @brief info struct
 * 
 * @details info struct
 * 
 * @param file_name
 * @param no  north texture
 * @param so  south texture
 * @param we  west texture
 * @param ea  east texture
 * @param floor  floor color
 * @param ceiling  ceiling color
 * @param height  map height
 * @param width  map width
 * @param map  map
 */
typedef struct s_info
{
	char	*file_name;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
	int		height;
	int		*width;
	char	**map;
}	t_info;

/**
 * @brief img struct
 * 
 * @details img struct
 * 
 * @param img  img
 * @param data  data
 * @param size_line  size line
 * @param bpp  bits per pixel
 * @param endian  endian
 * @param width  width
 * @param height  height
 */
typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

/**
 * @brief position struct
 * 
 * @details position struct
 * 
 * @param player_char  player char
 * @param pos_x  pos x
 * @param pos_y  pos y
 * @param dir_x  dir x
 * @param dir_y  dir y
 * @param plane_x  plane x
 * @param plane_y  plane y
 */
typedef struct s_position
{
	char	player_char;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_position;

/**
 * @brief mlx struct
 * 
 * @details mlx struct
 * 
 * @param mlx  mlx
 * @param win  win
 * @param texture  texture
 * @param canvas  canvas
 * @param buf  buf
 */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	texture[4];
	t_img	canvas;
	int		buf[WIN_HEIGHT][WIN_WIDTH];
}	t_mlx;

/**
 * @brief ray struct
 * 
 * @details ray struct
 * 
 * @param camera_x  camera x
 * @param dir_x  dir x
 * @param dir_y  dir y
 * @param map_x  map x
 * @param map_y  map y
 * @param side_dist_x  side dist x
 * @param side_dist_y  side dist y
 * @param delta_dist_x  delta dist x
 * @param delta_dist_y  delta dist y
 * @param perp_wall_dist  perp wall dist
 * @param step_x  step x
 * @param step_y  step y
 * @param hit  hit
 * @param side  side
 */
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

/**
 * @brief draw struct
 * 
 * @details draw struct
 * 
 * @param line_height  line height
 * @param draw_start  draw start
 * @param draw_end  draw end
 * @param tex_num  tex num
 * @param tex_x  tex x
 * @param tex_y  tex y
 * @param tex_pos  tex pos
 * @param step  step
 * @param color  color
 */
typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		color;
}	t_draw;

#endif
