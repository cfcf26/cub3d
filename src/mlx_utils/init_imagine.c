
#include "utils.h"

void	load_image(t_mlx *mlx, int idx, char *dir_img, t_img *img)
{
	t_info	*info;
	int		x;
	int		y;

	img->img = dir_img;
	info = get_info();
	img->data = (int *)mlx_get_data_addr(img->img, \
	&img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
		{
			info->text[idx][TILE_SIZE * y + x] = \
				img->data[TILE_SIZE * y + x];
		}
	}
	mlx_destroy_image(mlx->mlx, img->img);
}

void	get_buff(int **buff)
{
	int	i;
	int	j;

	buff = (int **)malloc(sizeof(int) * WIN_HEIGHT);
	if (!buff)
		ft_error("Error : buff malloc error(1)\n");
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		buff[i] = (int *)malloc(sizeof(int) * WIN_WIDTH);
		if (!buff[i])
			ft_error("Error : buff malloc error(2)\n");
	}
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			buff[i][j] = 0;
		}
	}
}

void	get_text(int **text, t_mlx *mlx, t_img img)
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
		while (++j < TILE_SIZE * TILE_SIZE)
			text[i][j] = 0;
	}
	load_image(mlx, 0, mlx->north, &img);
	load_image(mlx, 1, mlx->south, &img);
	load_image(mlx, 2, mlx->east, &img);
	load_image(mlx, 3, mlx->west, &img);
}

void	init_imagine(void)
{
	t_img	img;
	t_info	*info;
	t_mlx	*mlx;

	info = get_info();
	mlx = get_mlx();
	img = get_info()->img;
	get_buff(info->buf);
	get_text(info->text, mlx, img);
	img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data = \
	(int *)mlx_get_data_addr(&img.img, &img.bpp, &img.size_l, &img.endian);
}
