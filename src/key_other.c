
#include "cub3d.h"

void	turn_left(t_position *position)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = position->dir_x;
	position->dir_x = position->dir_x * cos(position->rot_speed) - \
	position->dir_y * sin(position->rot_speed);
	position->dir_y = olddir_x * sin(position->rot_speed) + \
	position->dir_y * cos(position->rot_speed);
	oldplane_x = position->plane_x;
	position->plane_x = position->plane_x * cos(position->rot_speed) - \
	position->plane_y * sin(position->rot_speed);
	position->plane_y = oldplane_x * sin(position->rot_speed) + \
	position->plane_y * cos(position->rot_speed);
}

void	turn_right(t_position *position)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = position->dir_x;
	position->dir_x = position->dir_x * cos(-position->rot_speed) - \
	position->dir_y * sin(-position->rot_speed);
	position->dir_y = olddir_x * sin(-position->rot_speed) + \
	position->dir_y * cos(-position->rot_speed);
	oldplane_x = position->plane_x;
	position->plane_x = position->plane_x * cos(-position->rot_speed) - \
	position->plane_y * sin(-position->rot_speed);
	position->plane_y = oldplane_x * sin(-position->rot_speed) + \
	position->plane_y * cos(-position->rot_speed);
}

int	red_button(t_cub3d *cub3d)
{
	write(1, "game finish!\n", 13);
	mlx_destroy_window(cub3d->mlx->mlx, cub3d->mlx->win);
	exit(0);
}
