
#include "utils.h"

t_player	*get_player(void)
{
	static t_player	*player = NULL;

	if (player == NULL)
	{
		player = ft_calloc(1, sizeof(t_info));
		return (player);
	}
	else
		return (player);
}
