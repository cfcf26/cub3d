
#include "utils.h"

t_ray_info	*get_ray_info(void)
{
	static t_ray_info	*ray_info;

	if (ray_info == NULL)
	{
		ray_info = ft_calloc(1, sizeof(t_ray_info));
		return (ray_info);
	}
	else
		return (ray_info);
}