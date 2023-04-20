
#include "cub3d.h"
#include "models.h"

void	make_ray(t_ray *ray, t_position *position, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = position->dir_x + position->plane_x \
	* ray->camera_x;
	ray->ray_dir_y = position->dir_y + position->plane_y \
	* ray->camera_x;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->map_x = (int)position->pos_x;
	ray->map_y = (int)position->pos_y;
}

void	get_sidedist(t_ray *ray, t_position *position)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (position->pos_x - ray->map_x) \
		* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - position->pos_x) \
		* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (position->pos_y - ray->map_y) \
		* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - position->pos_y) \
		* ray->delta_dist_y;
	}
}

void	dda_calc(t_ray *ray, t_position *position)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (get_info()->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - position->pos_x + \
		(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - position->pos_y + \
		(1 - ray->step_y / 2) / ray->ray_dir_y);
}

void	get_draw_info(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	get_wall_x(t_ray *ray, t_info *info, t_position *position)
{
	ray->tex_num = info->map[ray->map_x][ray->map_y];
	if (ray->side == 0)
		ray->wall_x = position->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = position->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	get_coord_texture(t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * (double)TILE_SIZE);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = TILE_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = TILE_SIZE - ray->tex_x - 1;
}

void	draw_line (int x, t_ray *ray, t_info *info)
{
	int	y;

	ray->step = 1.0;
	ray->tex_pos = \
	(ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TILE_SIZE - 1);
		ray->tex_pos += ray->step;
		ray->color = \
		info->text[ray->tex_num][TILE_SIZE * ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		info->buf[y][x] = ray->color;
	}
}

void	calc(t_cub3d *cub3d)
{
	t_position			*position;
	t_info				*info;
	t_ray				ray;
	int					x;

	position = cub3d->position;
	info = cub3d->info;
	ft_memset(&ray, 0, 1);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		make_ray(&ray, position, x);
		get_sidedist(&ray, position);
		dda_calc(&ray, position);
		get_draw_info(&ray);
		get_wall_x(&ray, info, position);
		get_coord_texture(&ray);
		draw_line(x, &ray, info);
		printf("camera_x : %f \n ray_dir_x : %f \n ray_dir_y : %f \n map_x : %d \n map_y : %d \n side_dist_x : %f \n side_dist_y : %f \n delta_dist_x : %f \n delta_dist_y : %f \n perp_wall_dist : %f \n step_x : %d \n step_y : %d \n hit : %d \n side : %d \n line_height : %d \n draw_start : %d \n draw_end : %d \n tex_num : %d \n wall_x : %f \n tex_x : %d \n tex_y : %d \n tex_pos : %f \n step : %f \n color : %d", ray.camera_x, ray.ray_dir_x, ray.ray_dir_y, ray.map_x, ray.map_y, ray.side_dist_x, ray.side_dist_y, ray.delta_dist_x, ray.delta_dist_y, ray.perp_wall_dist, ray.step_x, ray.step_y, ray.hit, ray.side, ray.line_height, ray.draw_start, ray.draw_end, ray.tex_num, ray.wall_x, ray.tex_x, ray.tex_y, ray.tex_pos, ray.step, ray.color);
		exit(0);
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
			cub3d->info->img.data[y * WIN_WIDTH + x] = cub3d->info->buf[y][x];
		}
		mlx_put_image_to_window(cub3d->mlx->mlx, cub3d->mlx->win, \
		cub3d->info->img.img, 0, 0);
	}
}

int	main_loop(t_cub3d *cub3d)
{
	calc(cub3d);
	draw(cub3d);
	return (0);
}
