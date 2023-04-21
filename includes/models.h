/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:39:48 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/22 02:43:22 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELS_H
# define MODELS_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64
# define VALID_MAP_CHAR "012NSEW "
# define VALID_PLAYER_CHAR "NSEW"
# define NOT_WALL "0NEWS"

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	texture[4];
	t_img	canvas;
	int		buf[WIN_HEIGHT][WIN_WIDTH];
}	t_mlx;

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
