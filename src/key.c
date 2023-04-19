
#include "cub3d.h"

void	move_up(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x + position->dir_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x += position->dir_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)(position->pos_y + \
	position->dir_y * position->move_speed)])
		position->pos_y += position->dir_y * position->move_speed;
}

void	move_down(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x - position->dir_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x -= position->dir_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)(position->pos_y - \
	position->dir_y * position->move_speed)])
		position->pos_y -= position->dir_y * position->move_speed;
}

void	move_left(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x - position->plane_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x -= position->plane_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)(position->pos_y - \
	position->plane_y * position->move_speed)])
		position->pos_y -= position->plane_y * position->move_speed;
}

void	move_right(t_info *info, t_position *position)
{
	if (!info->map[(int)(position->pos_x + position->plane_x * \
	position->move_speed)][(int)(position->pos_y)])
		position->pos_x += position->plane_x * position->move_speed;
	if (!info->map[(int)(position->pos_x)][(int)(position->pos_y + \
	position->plane_y * position->move_speed)])
		position->pos_y += position->plane_y * position->move_speed;
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
		move_down(info, position);
	else if (key == KEY_A)
		move_left(info, position);
	else if (key == KEY_D)
		move_right(info, position);
	else if (key == KEY_LEFT)
		turn_left(position);
	else if (key == KEY_RIGHT)
		turn_right(position);
	else if (key == KEY_ESC)
	{
		write(1, "cub3d finish!\n", 15);
		exit (0);
	}
	//mlx_clear_window(cub3d->mlx.mlx, cub3d->mlx.win);
	return (0);
}
