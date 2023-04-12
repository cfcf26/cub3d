
#include "parser.h"

static void	check_player_north_side(char **tmp_map, int x, int y)
{
	if (!(tmp_map[x][y] == '0' || tmp_map[x][y] == '1'))
		write_err("Error : player location is strange (1)\n");
}

static void	check_player_south_side(char **tmp_map, int x, int y)
{
	if (!(tmp_map[x][y] == '0' || tmp_map[x][y] == '1'))
		write_err("Error : player location is strange (2)\n");
}

static void	check_player_west_side(char **tmp_map, int x, int y)
{
	if (!(tmp_map[x][y] == '0' || tmp_map[x][y] == '1'))
		write_err("Error : player location is strange (3)\n");
}

static void	check_player_east_side(char **tmp_map, int x, int y)
{
	if (!(tmp_map[x][y] == '0' || tmp_map[x][y] == '1'))
		write_err("Error : player location is strange (4)\n");
}

void	validate_player_location(char **tmp_map, int x, int y)
{
	check_player_north_side(tmp_map, x - 1, y);
	check_player_south_side(tmp_map, x + 1, y);
	check_player_west_side(tmp_map, x, y - 1);
	check_player_east_side(tmp_map, x, y + 1);
}
