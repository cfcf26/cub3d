
#include "utils.h"

t_cub3d	*get_cub3d(void)
{
	static t_cub3d	cub3d;

	return (&cub3d);
}