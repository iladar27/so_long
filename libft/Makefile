# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 14:35:49 by ilgaynet          #+#    #+#              #
#    Updated: 2024/10/29 14:36:21 by ilgaynet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a

CFLAGS      = -Wall -Wextra -Werror

FILES       = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c\
              ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
              ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
              ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
              ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
              ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ         = $(FILES:.c=.o)
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@ranlib $@
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "Object files deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

normi: $(FILES)
	norminette $(FILES)

test: main.c $(NAME)
	@gcc $(CFLAGS) main.c $(NAME) && ./a.out

git:
	git add .
	git commit -m "$m"
	git push origin main

.PHONY: all clean fclean re normi test git

