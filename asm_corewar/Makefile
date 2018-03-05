# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 18:26:45 by lmartin-          #+#    #+#              #
#    Updated: 2018/02/15 18:26:47 by lmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = main.c
SRC_E = $(addprefix $(SRCDIR)/, $(SRC))
SRO = $(SRC_E:%.c=$(BUILDDIR)/%.o)
LIB = ../libft/libft.a
FLIB = -Llibft -lft

BUILDDIR = object
SRCDIR = src

FLAGS = -Wall -Wextra -Werror
ifdef DEBUG
  FLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(BUILDDIR) $(SRO)
	gcc $(FLAG) $(SRO) -o $(NAME) $(LIB) $(FLIB)

$(BUILDDIR):
	mkdir $(BUILDDIR)
	mkdir $(BUILDDIR)/$(SRCDIR)

$(BUILDDIR)/%.o: %.c
	gcc $(FLAGS) -I ./incs/ -c $< -o $@

clean:
	rm -rf ./object

fclean: clean
	rm -f $(NAME)

re: fclean all
