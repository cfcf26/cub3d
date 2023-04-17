
#include "cub3d.h"

void	make_ray(t_ray *ray, int x)
{
	ray->camera_x = 2 * x / get_info()->(double)width - 1;
	ray->raydir_x = get_position()->dir_x + get_position()->plane_x \
	* ray->camera_x;
	ray->raydir_y = get_position()->dir_y + get_position()->plane_y \
	* ray->camera_x;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->map_x = get_position()->(int)pos_x;
	ray->map_y = get_position()->(int)pos_y;
}

void	get_sidedist(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (get_position()->pos_x - ray->map_x) \
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
		ray->sidedist_y = (get_position()->pos_y - ray->map_y) \
		* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - get_position()->pos_y) \
		* ray->deltadist_y;
	}
}

void	dda_calc(t_ray *ray)
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
		ray->perpwalldist = (ray->map_x - get_position()->pos_x + \
		(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - get_position()->pos_y + \
		(1 - ray->step_y / 2) / ray->raydir_y);
}

void	get_draw_info(t_ray *ray)
{
	const int	wall_h = (int)(WIN_HEIGHT / ray->perpwalldist);
	int			draw_start;
	int			draw_end;
	int			i;

	i = draw_start;
	while (++i < draw_end)
	{
		
	}
}

void	calc(void)
{
	int		x;
	t_ray	*ray;

	x = -1;
	ray->hit = 0;
	while (++x < WIN_WIDTH)
	{
		make_ray(ray, x);
		get_sidedist(ray);
		dda_calc(ray);
		get_hegiht(ray);
		get_draw_info(wall_height, ray);
	}
}

int	main_loop(void)
{
	calc();
	draw();
}
