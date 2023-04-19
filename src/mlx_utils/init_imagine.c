
#include "utils.h"

void	get_buff(int **buff)
{
	int	i;
	int	j;

	buff = (int **)malloc(sizeof(int) * get_info()->height);
	i = -1;
	while (++i < get_info()->height)
	{
		buff[i] = (int *)malloc(sizeof(int) * get_info()->width);
		j = -1;
		while (++j < get_info()->width)
		{
			buff[i][j] = 0;
		}
	}
}

void	get_text(int **text)
{
	int	i;
	int	j;

	text = (int **)malloc(sizeof(int *) * 4);
	if (!text)
		ft_error("Error : text malloc error (1)\n");
	i = -1;
	while (++i < 4)
	{
		text[i] = (int *)malloc(sizeof(int) * (TILE_SIZE * TILE_SIZE));
		if (!text[i])
			ft_error("Error : text malloc error(2)\n");
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TILESIZE * TILE_SIZE)
			text[i][j] = 0;
	}
}

void	init_imagine(void)
{
	const t_img		img = get_info()->img;
	const t_info	*info = get_info();

	get_buff(info->buff);
	get_text(info->text);
	img.img = mlx_new_img(get_info()->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data = \
	(int *)mlex_get_data_addr(&img.img, &img.bqq, &img.size_l, &img.endian);
}
