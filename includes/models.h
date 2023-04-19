/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:39:48 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/17 19:44:35 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELS_H
# define MODELS_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64
# define VALID_MAP_CHAR "012NSEW "
# define VALID_PLAYER_CHAR "NSEW"
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3

# define RED_BUTTON 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_heigth;
}	t_img;

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
	int		**text;
	int		**buf;
	t_img	img;
}	t_info;

typedef struct s_position
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	// double	(*get_time)(void);
}	t_position;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_mlx;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
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
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		color;
}	t_ray;

typedef struct s_cub3d
{
	t_info		*info;
	t_mlx		*mlx;
	t_position	*position;
}	t_cub3d;

#endif
