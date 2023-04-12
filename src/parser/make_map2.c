
#include "parser.h"

void	reset_map(char **map, int size[2])
{
	int	i;
	int	j;

	i = 0;
	while (i < size[1])
	{
		j = 0;
		while (j < size[0])
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char	**make_map2(char *file_name, int size[2])
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	i = -1;
	map = (char **)malloc(sizeof(char *) * size[1]);
	while (++i < size[1])
		map[i] = (char *)malloc(sizeof(char) * size[0]);
	reset_map(map, size);
	fd = open(file_name, O_RDONLY);
	pass_before_map(fd);
	line = pass_newline(fd);
	i = -1;
	while (++i < size[1])
	{
		ft_memcpy(map[i], line, check_line_size(line));
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
