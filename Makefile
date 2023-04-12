# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:40:03 by ekwak             #+#    #+#              #
#    Updated: 2023/04/11 22:31:27 by ekwak            ###   ########.fr        #
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

SRCS = $(wildcard src/*.c) \
	   $(wildcard src/parser/*.c) \
       $(wildcard utils/*.c) \
	   

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
