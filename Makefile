# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:45:41 by tbeauman          #+#    #+#              #
#    Updated: 2025/01/16 13:10:37 by tbeauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fract-ol
MLXPATH=./minilibx-linux
MLX=minilibx-linux/libmlx_Linux.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -g3 -I./minilibx-linux
MLXFLAGS=$(MLX) -I$(MLXPATH) -lX11 -lXext 
SRCS=main.c palettes.c key_hooks.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) -lm

$(MLX):
	make -C $(MLXPATH) 

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re