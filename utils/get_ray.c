
#include "utils.h"

t_ray	*get_ray(void)
{
	static t_ray	*ray;

	if (ray == NULL)
	{
		ray = ft_calloc(1, sizeof(t_ray));
		return (ray);
	}
	else
		return (ray);
}
