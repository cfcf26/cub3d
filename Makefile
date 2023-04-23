# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:40:03 by ekwak             #+#    #+#              #
#    Updated: 2023/04/23 15:46:52 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
LIBFT = libft/libft.a
LIBFT_DIR = libft
MLX_DIR = minilibx_opengl_20191021
MLX = $(MLX_DIR)/libmlx.a
INCLUDES = -I./includes -I./$(LIBFT_DIR) -I./$(MLX_DIR)
LFLAGS = -L./$(LIBFT_DIR) -lft -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRCS = utils/exit_on_memory_failure.c \
       utils/ft_error.c \
       utils/get_info.c \
       utils/get_mlx.c \
       utils/get_position.c \
       utils/get_ray.c \
       utils/parse_error.c \
       utils/pass_newline.c \
       utils/pass_not_newline.c \
       utils/test_print_info.c \
       utils/test_printf.c \
       utils/validate_file_extension.c \
       src/key/key_press.c \
       src/key/move.c \
       src/key/rotate.c \
       src/main.c \
       src/mlx_utils/draw.c \
       src/mlx_utils/get_texture.c \
       src/mlx_utils/init_mlx_struct.c \
       src/mlx_utils/synchronize_direction.c \
       src/parser/get_floor_ceiling_color.c \
       src/parser/get_map.c \
       src/parser/get_map_size.c \
       src/parser/get_texture_paths.c \
       src/parser/parser.c \
       src/parser/validate_file.c \
       src/parser/validate_floor_ceiling_colors.c \
       src/parser/validate_map_characters.c \
       src/parser/validate_map_walls.c \
       src/parser/validate_texture_paths.c \
       src/position/get_position_from_info.c \
       src/raycaste/calc_dda.c \
       src/raycaste/calc_draw_start_and_end.c \
       src/raycaste/calc_step_and_side_dist.c \
       src/raycaste/calc_texture.c \
       src/raycaste/calculation.c \
       src/raycaste/draw_wall.c \
       src/raycaste/init_ray.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LFLAGS)

debug: CFLAGS += $(DEBUG) -DDEBUG_MODE # DEBUG 플래그 추가
debug: all  # debug 규칙 추가

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
