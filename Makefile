# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 15:21:48 by ilgaynet          #+#    #+#              #
#    Updated: 2025/02/10 11:58:11 by ilgaynet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
MLX_DIR     = ./minilibx
MLX_LIB     = -L$(MLX_DIR) -lmlx
LIBS        = -lX11 -lXext -lGL -lGLU -lm

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

GNL_SRCS    = getnextline/get_next_line.c getnextline/get_next_line_utils.c
GNL_OBJS    = $(GNL_SRCS:.c=.o)

SRCS        = src/new_window.c src/read_map.c src/draw_map.c src/creat_exit.c src/player.c src/verify_map.c src/helper.c src/check_accessibility.c src/ft_strdup_2d.c $(GNL_SRCS)
OBJS        = $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) $(PRINTF) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o:        %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)/includes -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean:     clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re:         fclean all

.PHONY:     all clean fclean re
