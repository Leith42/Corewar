# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 04:01:19 by mmatime           #+#    #+#              #
#    Updated: 2018/03/08 04:01:21 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
CC = gcc
INCLUDE = -Ilibft -Iinclude
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
SRC_ASM = srcs/main.c srcs/read.c srcs/write.c srcs/check_header.c
LIB_PATH = ./libft/
LIB_BIN = $(LIB_PATH)libft.a
SRC_PATH = ./src/

OBJ_SRC_ASM = $(SRC_ASM:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC_ASM)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC_ASM) $(INCLUDE) $(CFLAGS) $(LIB_BIN)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ_SRC_ASM)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
