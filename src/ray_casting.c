
#include "cub3d.h"

void	make_ray(t_ray *ray, t_position *position, int x)
{
	ray->camera_x = 2 * x / position->(double)WIN_WIDTH - 1;
	ray->raydir_x = position->dir_x + position->plane_x \
	* ray->camera_x;
	ray->raydir_y = position->dir_y + position->plane_y \
	* ray->camera_x;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->map_x = position->(int)pos_x;
	ray->map_y = position->(int)pos_y;
}

void	get_sidedist(t_ray *ray, t_position *position)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (position->pos_x - ray->map_x) \
		* ray->deltadis_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) \
		* ray->deltadis_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (position->pos_y - ray->map_y) \
		* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - position->pos_y) \
		* ray->deltadist_y;
	}
}

void	dda_calc(t_ray *ray, t_position *position)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (get_info()->map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - position->pos_x + \
		(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - position->pos_y + \
		(1 - ray->step_y / 2) / ray->raydir_y);
}

void	get_draw_info(t_ray *ray, t_info *info)
{
	ray->line_height = (int)(WIN_HEIGTH / ray->perpwalldist);
	ray->draw_start = -(ray->line_height) / 2 + height / 2;
	if (draw_start < 0)
		draw_start = 0;
	ray->draw_end = ray->line_height / 2 + hieght / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WINHEGITH - 1;
}

void	get_wall_x(t_ray *ray, t_info *info, t_position *position)
{
	ray->tex_num = info->map[ray->map_x][ray->map_y];
	if (ray->side == 0)
		ray->wall_x = position->pos_y + ray->perwalldist * ray->raydir_y;
	else
		ray->wall_x = position->pos_x + ray->perwalldist * ray->raydir_x;
	ray->wall_x -= floor(wall_x);
}

void	get_coord_texture(t_ray *ray)
{
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = TILE_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = TILE_SIZE - ray->tex_x - 1;
}

void	draw_line (int x, t_ray *ray, t_info *info)
{
	int	y;

	ray->step = 1.0;
	ray->tex_pos = \
	(ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TILE_SIZE - 1);
		ray->tex_pos += step;
		ray->color = \
		info->text[ray->tex_num][TILE_SIZE * ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		info->buff[y][x] = color;
	}
}

void	calc(t_cub3d *cub3d)
{
	t_position			*position;
	t_info				*info;
	t_ray				*ray;
	int					x;

	position = cub3d->position;
	info = cub3d->info;
	ray->hit = 0;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		make_ray(ray, position, x);
		get_sidedist(ray, position);
		dda_calc(ray, position);
		get_draw_info(ray, info);
		get_wall_x(ray, info, position);
		get_coord_texture(ray, info, position);
		draw_line(x, ray, info);
	}
}

void	draw(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			cub3d->info->img.data[y * WIN_WIDTH + x] = cub3d->info->buff[y][x];
		}
		mlx_put_image_to_window(cub3d->info->mlx, cub3d->info->win, \
		cub3d->info->img.img, 0, 0);
	}
}

int	main_loop(t_cub3d *cub3d)
{
	calc(cub3d);
	draw(cub3d);
	return (0);
}
