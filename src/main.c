/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:30:45 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/21 01:05:44 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_canvas(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	mlx->canvas.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->canvas.data = (int *)mlx_get_data_addr(mlx->canvas.img, \
						&mlx->canvas.bpp, &mlx->canvas.size_line, \
						&mlx->canvas.endian);
}

void	calc_step_and_side_dist(t_ray *ray, const t_position *position)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (position->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - position->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (position->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - position->pos_y) * ray->delta_dist_y;
	}
}

void	calc_dda(t_ray *ray)
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
		ray->perp_wall_dist = (ray->map_x - get_position()->pos_x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - get_position()->pos_y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
}

void	calc_draw_start_and_end(t_draw *draw, t_ray *ray)
{
	draw->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
	// printf("draw_line_height = %d, ray->perp_wall_dist = %f\n", draw->line_height, ray->perp_wall_dist);
	// printf("draw_start = %d, draw_end = %d ", draw->draw_start, draw->draw_end);
	// exit(0);
}

void	calc_texture(t_draw *draw, t_ray *ray)
{
	double	wall_x;
	t_position *position = get_position();

	if (ray->side == 0)
		wall_x = position->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = position->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * (double)TILE_SIZE);
	if (ray->side == 0 && ray->dir_x > 0)
		draw->tex_x = TILE_SIZE - draw->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		draw->tex_x = TILE_SIZE - draw->tex_x - 1;
	draw->step = 1.0 * TILE_SIZE / draw->line_height;
	draw->tex_pos = (draw->draw_start - WIN_HEIGHT / 2 + draw->line_height / 2) * draw->step;
	if (ray->side == 0 && ray->dir_x < 0)
		draw->tex_num = 0;
	else if (ray->side == 0 && ray->dir_x >= 0)
		draw->tex_num = 1;
	else if (ray->side == 1 && ray->dir_y < 0)
		draw->tex_num = 2;
	else if (ray->side == 1 && ray->dir_y >= 0)
		draw->tex_num = 3;
}

void	draw_wall(t_draw *draw, t_ray *ray, t_mlx *mlx, int x)
{
	int	y;
	int	color;

	color = 0;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		draw->tex_y = (int)draw->tex_pos & (TILE_SIZE - 1);
		draw->tex_pos += draw->step;
		color = mlx->texture[draw->tex_num].data[TILE_SIZE * draw->tex_y + draw->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		mlx->buf[y][x] = color;
		y++;
	}
}


void	calculation(void)
{
	int					x;
	t_ray				ray;
	t_draw				draw;
	const t_position	*position = get_position();

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, position, x);
		calc_step_and_side_dist(&ray, position);
		calc_dda(&ray);
		calc_draw_start_and_end(&draw, &ray);
		calc_texture(&draw, &ray);
		draw_wall(&draw, &ray, get_mlx(), x);
		x++;
	}
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx->canvas.data[y * WIN_WIDTH + x] = mlx->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->canvas.img, 0, 0);
}

void	reset_buf(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			mlx->buf[i][j] = 0;
	}
}

int	main_loop(void)
{
	calculation();
	draw(get_mlx());
	reset_buf(get_mlx());
	return (0);
}

int	main(int argc, char **argv)
{
	parser(argc, argv);
	init_mlx_struct();
	get_position_from_info();
	init_canvas();
	mlx_loop_hook(get_mlx()->mlx, &main_loop, 0);
	mlx_loop(get_mlx()->mlx);
	test_printf("test");
	test_print_info();
	return (0);
}
