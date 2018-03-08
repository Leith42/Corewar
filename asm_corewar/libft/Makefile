# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/19 23:35:21 by mmatime           #+#    #+#              #
#    Updated: 2018/02/19 17:48:33 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
ft_strlen.c ft_strlen_n.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_free_tab.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strjoinfree.c ft_strjoin_precision.c ft_strjoin_custom.c \
ft_strtrim.c ft_strsplit.c \
ft_putchar.c ft_putstr.c ft_strlen_plus.c ft_putstr_n.c ft_putendl.c ft_putnbr.c ft_putnbr_c.c ft_putchar_fd.c ft_putstrtab.c ft_putinttab.c ft_strrev.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_itoa_max.c ft_itoa_unsigned.c ft_itoa_umax.c ft_itoa_minus.c ft_itoa_plus.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c ft_longtoi.c \
get_next_line.c ft_strjoin_n.c ft_strdup_n.c ft_strdup_mod.c ft_epurspace.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
