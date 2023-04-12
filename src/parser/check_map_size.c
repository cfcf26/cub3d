
#include "parser.h"

int	check_line_size(char *line)
{
	int	size;

	size = 0;
	if (ft_strchr(line, '\n'))
		size = ft_strlen(line) - 1;
	else
		size = ft_strlen(line);
	return (size);
}

void	check_map_size(char *file_name, int size[2])
{
	int		fd;
	int		tmp;
	int		width;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	pass_before_map(fd);
	line = pass_newline(fd);
	if (!line)
		write_err("Error : Map is empty (2)\n");
	width = 0;
	height = 0;
	while (line)
	{
		tmp = 0;
		tmp = check_line_size(line);
		if (tmp > width)
			width = tmp;
		height++;
		free(line);
		line = get_next_line(fd);
	}
	size[0] = width;
	size[1] = height;
}
