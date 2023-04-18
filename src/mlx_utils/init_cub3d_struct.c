
#include "utils.h"

t_cub3d	*init_cub3d_struct(void)
{
	t_cub3d	*cub3d;

	cub3d = get_cub3d();
	cub3d->info = get_info();
	cub3d->mlx = get_mlx();
	cub3d->position = get_position();
	return (cub3d);
}
