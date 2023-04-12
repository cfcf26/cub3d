
#include "parser.h"

static void	check_north_side(char **tmp_map, int x, int y)
{
	if (tmp_map[x][y] == '\0' || tmp_map[x][y] == ' ' || \
	tmp_map[x][y] == '\n')
		write_err("Error : Map wall is strange (1)\n");
}

static void	check_south_side(char **tmp_map, int x, int y)
{
	if (tmp_map[x][y] == '\0' || tmp_map[x][y] == ' ' || \
	tmp_map[x][y] == '\n')
		write_err("Error : Map wall is strange (2)\n");
}

static void	check_west_side(char **tmp_map, int x, int y)
{
	if (tmp_map[x][y] == '\0' || tmp_map[x][y] == ' ' || \
	tmp_map[x][y] == '\n')
		write_err("Error : Map wall is strange (3)\n");
}

static void	check_east_side(char **tmp_map, int x, int y)
{
	if (tmp_map[x][y] == '\0' || tmp_map[x][y] == ' ' || \
	tmp_map[x][y] == '\n')
		write_err("Error : Map wall is strange (4)\n");
}

void	validate_map_wall(char **tmp_map, int size[2])
{
	const char	set[4] = "NSWE";
	int			x;
	int			y;

	x = -1;
	while (++x < size[1])
	{
		y = -1;
		while (tmp_map[x][++y] != '\0')
		{
			if (tmp_map[x][y] == '0')
			{
				check_north_side(tmp_map, x - 1, y);
				check_south_side(tmp_map, x + 1, y);
				check_west_side(tmp_map, x, y - 1);
				check_east_side(tmp_map, x, y + 1);
			}
			if (ft_strchr(set, tmp_map[x][y]))
				validate_player_location(tmp_map, x, y);
		}
	}
}
