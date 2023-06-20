# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 16:30:24 by hrahovha          #+#    #+#              #
#    Updated: 2023/03/19 18:36:15 by hrahovha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

SRC = 	src/main.c						\
		src/anim.c						\
		src/check.c						\
		src/check2.c					\
		src/door.c						\
		src/empty.c						\
		src/ft_error_print.c			\
		src/girl.c						\
		src/map.c						\
		src/logic.c						\
		src/move_d.c					\
		src/move_l.c					\
		src/move_r.c					\
		src/move_u.c					\
		src/player_move.c				\
		src/walls.c						\
		src/win.c						\
		utils/ft_strlen.c				\
		utils/ft_strdup.c				\
		utils/ft_memset.c				\
		utils/ft_split.c				\
		utils/ft_substr.c				\
		utils/ft_itoa.c					\
		utils/ft_atoi.c					\
		utils/ft_printf.c				\
		utils/ft_strchr.c				\
		utils/ft_strjoin.c				\
		utils/ft_strrncmp.c				\
		utils/get_next_line.c			\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re