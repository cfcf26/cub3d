
#include "parser.h"

void	make_map(char *file_name, char ***tmp_map)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*result;
	char	**map;

	map = NULL;
	fd = open(file_name, O_RDONLY);
	pass_before_map(fd);
	result = pass_newline(fd);
	if (!result)
		write_err("Error : Map is empty(3)\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin(result, line);
		free(result);
		result = tmp;
		free(line);
	}
	*tmp_map = ft_split(result, '\n');
	free(result);
}
