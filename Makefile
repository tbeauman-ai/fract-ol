# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:45:41 by tbeauman          #+#    #+#              #
#    Updated: 2025/01/19 16:00:27 by tbeauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fract-ol
MLXPATH=./minilibx-linux
MLX=minilibx-linux/libmlx_Linux.a
CC=cc
CFLAGS=-O2 -Wall -Wextra -Werror -g3 -I./minilibx-linux
MLXFLAGS=$(MLX) -I$(MLXPATH) -lX11 -lXext 
SRCS=main.c palettes.c key_hooks.c mouse_hooks.c cpx_tools.c \
	fractal_tools.c draw_functions.c clear_tools.c recurrences.c \
	
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