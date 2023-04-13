/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:39:48 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/14 01:21:32 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELS_H
# define MODELS_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64

typedef struct s_info
{
	char	*file_name;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
	int		height;
	int		*width;
	char	**map;
}	t_info;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_mlx;

#endif
