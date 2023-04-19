
#include "cub3d"

void	move_up(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x + position->dir_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x += position->dir_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)position->pos_y + \
	position->dir_y * position->move_speed])
		position->pos_y += position->dir_y * position->move_speed;
}

void	move_down(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x - position->dir_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x -= position->dir_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)position->pos_y - \
	position->dir_y * position->move_speed])
		position->pos_y -= position->dir_y * position->move_speed;
}

void	move_left(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x - position->plane_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x -= position->plane_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)position->pos_y - \
	position->plane_y * position->move_speed])
		position->pos_y -= position->plane_y * position->move_speed;
}

void	move_right(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x + position->plane_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x += position->plane_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)position->pos_y + \
	position->plane_y * position->move_speed])
		position->pos_y += position->plane_y * position->move_speed;
}

void	turn_left(t_info *info, t_position *position)
{
	double	olddir_x;
	double	oldplane_x;

	oldddir_x = position->dir_x;
	position->dir_x = position->dir_x * cos(position->rot_speed) - \
	position->dir_y * sin(position->rot_speed);
	position->dir_y = olddir_x->dir_y * sin(position->rot_speed) + \
	position->dir_y * cos(position->rot_speed);
	oldplane_x = position->plane_x;
	position->plane_x = position->plane_x * cos(position->rotspeed) - \
	position->plane_y * sin(position->rot_speed);
	position->plane_y = oldplane_x * sin(position->rot_speed) + \
	position->plane_y * cos(position->rot_speed);
}

void	turn_right(t_info *info, t_position *position)
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

int	key_press(int key, t_cub3d *cub3d)
{
	t_info		*info;
	t_position	*position;

	info = cub3d->info;
	position = cub3d->position;
	if (key == KEY_W)
		move_up(info, position);
	else if (key == KEY_S)
		move_dow(info, position);
	else if (key == KEY_A)
		move_left(info, position);
	else if (key == KEY_D)
		move_right(info, position);
	else if (key == KEY_LEFT)
		turn_left(info, position);
	else if (key == KEY_RIGHT)
		turn_right(info, position);
	else if (key == KEY_ESC)
	{
		write(1, "cub3d finish!\n", 15);
		exit (0);
	}
	mlx_clear_window(cub3d->mlx->mlx, cub3d->mlx->win);
	main_loop(cub3d);
	return (0);
}
