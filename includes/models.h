/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:39:48 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/14 16:55:47 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELS_H
# define MODELS_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64

typedef struct s_info
{
	char	*file_name;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	player_spawn;
	int		floor[3];
	int		ceiling[3];
	int		height;
	int		*width;
	char	**map;
}	t_info;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_mlx;

typedef struct s_player_coord
{
	double	x;
	double	y;
}	t_player;

typedef struct s_direct_coord
{
	double	x;
	double	y;
	char	player_spawn;
}	t_dir;

typedef struct s_ray_info
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	old_time;
}	t_ray_info;

typedef struct s_ray_casting
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	prerpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}	t_ray;

#endif
