# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 21:46:35 by lmartin-          #+#    #+#              #
#    Updated: 2016/11/19 22:47:28 by lmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_CLASS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_tolower.c ft_toupper.c
SRC_CONVERT = ft_atoi.c ft_itoa.c
SRC_LIST = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
ft_lstnew.c
SRC_MATH = ft_factorial.c ft_is_prime.c ft_power.c ft_sqrt.c
SRC_MEM = ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memdel.c ft_memmove.c ft_memset.c
SRC_PUT = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
SRC_STR = ft_bzero.c ft_strclr.c ft_strdel.c ft_striter.c ft_strlcat.c \
ft_strmapi.c ft_strncpy.c ft_strnstr.c ft_strstr.c ft_swap.c \
ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strlen.c \
ft_strncat.c ft_strnequ.c ft_strrchr.c ft_strsub.c ft_strchr.c ft_strcpy.c \
ft_strequ.c ft_strjoin.c ft_strmap.c ft_strncmp.c ft_strnew.c \
ft_strsplit.c ft_strtrim.c

SRCDIR_CLASS = class
SRCDIR_CONVERT = convert
SRCDIR_LIST = list
SRCDIR_MATH = math
SRCDIR_MEM = mem
SRCDIR_PUT = put
SRCDIR_STR = str

BUILDDIR = object
SRCDIR = src

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRCDIR_CLASS)/, $(SRC_CLASS)) \
	$(addprefix $(SRCDIR_CONVERT)/, $(SRC_CONVERT)) \
	$(addprefix $(SRCDIR_LIST)/, $(SRC_LIST)) \
	$(addprefix $(SRCDIR_MATH)/, $(SRC_MATH)) \
	$(addprefix $(SRCDIR_MEM)/, $(SRC_MEM)) \
	$(addprefix $(SRCDIR_PUT)/, $(SRC_PUT)) \
	$(addprefix $(SRCDIR_STR)/, $(SRC_STR))

SRO = $(SRC:%.c=$(BUILDDIR)/%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(BUILDDIR) $(SRO)
	ar rc $(NAME) $(SRO)
	ranlib $(NAME)

$(BUILDDIR):
	mkdir $(BUILDDIR)
	mkdir $(BUILDDIR)/$(SRCDIR_CLASS)
	mkdir $(BUILDDIR)/$(SRCDIR_CONVERT)
	mkdir $(BUILDDIR)/$(SRCDIR_LIST)
	mkdir $(BUILDDIR)/$(SRCDIR_MATH)
	mkdir $(BUILDDIR)/$(SRCDIR_MEM)
	mkdir $(BUILDDIR)/$(SRCDIR_PUT)
	mkdir $(BUILDDIR)/$(SRCDIR_STR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	gcc $(FLAG) -I ./incs/ -c $< -o $@

clean:
	rm -f $(SRO)

fclean: clean
	rm -f $(NAME)

re: fclean all
