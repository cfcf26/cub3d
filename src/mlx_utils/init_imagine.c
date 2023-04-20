
#include "utils.h"

// void	load_image(t_mlx *mlx, int idx, char *path, t_img *img)
// {
// 	t_info	*info;
// 	int		x;
// 	int		y;
// 	int		height;
// 	int		width;

// 	img->img = mlx_xpm_file_to_image(mlx->mlx, \
// 		path, &width, &height);
// 	info = get_info();
// 	img->data = (int *)mlx_get_data_addr(img->img, \
// 	&img->bpp, &img->size_l, &img->endian);
// 	y = 0;
// 	idx = 0;
// 	x = 0;
// 	while (y < height)
// 	{
// 		x = 0;
// 		while (++x < width)
// 		{
// 			info->text[idx][width * y + x] = \
// 				img->data[width * y + x];
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_destroy_image(mlx->mlx, img->img);
// }

void	load_image(t_mlx *mlx, int *texture, t_img *img, void *mlx_xpm_img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_img;
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_heigth)
	{
		x = -1;
		while (++x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(mlx->mlx, img->img);
}

void	load_texture(t_info *info, t_mlx *mlx)
{
	t_img	img;

	load_image(mlx, info->text[0], &img, mlx->north);
	load_image(mlx, info->text[1], &img, mlx->south);
	load_image(mlx, info->text[2], &img, mlx->west);
	load_image(mlx, info->text[3], &img, mlx->east);

}

void	get_buff(int **buff)
{
	int	i;
	int	j;

	buff = (int **)malloc(sizeof(int *) * WIN_HEIGHT);
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

void	get_text(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 64 * 64)
		{
			printf("%d	%d\n", i, j);
			info->text[i][j] = 0;
		}
	}
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
	// get_text(info);
	load_texture(info, mlx);
	img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data = \
	(int *)mlx_get_data_addr(&img.img, &img.bpp, &img.size_l, &img.endian);
}
