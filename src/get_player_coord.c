
#include "cub3d.h"

void	get_player_coord(void)
{
	const char	set[4] = "NSEW";
	char		spwan;
	int			i;
	int			j;

	i = -1;
	while (++i < get_info()->height)
	{
		j = -1;
		while (++j < get_info()->width)
		{
			if (ft_strchr(set, get_info()->map[i][j]))
			{
				get_player()->player.x = j;
				get_player()->player.y = i;
				spawn = ft_strchr(set, get_info()->map[i][j]);
				get_player()->player.spawn = spawn;
			}
		}
	}
}