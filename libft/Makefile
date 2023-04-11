# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 23:21:56 by ekwak             #+#    #+#              #
#    Updated: 2023/04/10 22:06:09 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar
ARFLAGS = -crs
RM = rm
RMFLAGS = -f
SRCS =  ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_memchr.c ft_memcmp.c ft_strncmp.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strmapi.c ft_striteri.c ft_strtrim.c ft_itoa.c \
		get_next_line.c get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

$(NAME)	:
				$(CC) $(CFLAGS) -c $(SRCS) -I./
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
				$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
				$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re
