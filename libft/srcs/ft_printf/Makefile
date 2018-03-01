# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 01:13:53 by gudemare          #+#    #+#              #
#    Updated: 2018/03/01 18:31:23 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================== Project ===================================

NAME			=	ft_printf.o

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror

PROJECT_H_DIR	=	../../incs
PROJECT_HEADERS	=	ft_printf.h
IFLAGS			=	-I $(PROJECT_H_DIR)

COMPILE.c		=	$(CC) $(CFLAGS) $(IFLAGS)

SRCS_DIR		=	srcs/
SRCS_LIST		=	\
					conv_c.c \
					conv_d.c \
					conv_o.c \
					conv_p.c \
					conv_s.c \
					conv_u.c \
					conv_x.c \
					fill_spec.c \
					ft_anytoa.c \
					ft_get_args.c \
					ft_printf.c \
					ft_uanytoa.c \
					ft_uanytoa_base.c \
					handle_conv.c
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR		=	./objs/
OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

#================================== Graphics ===================================

END_GRAPHICS	=	\e[0m
BOLD			=	\e[1m
DARK			=	\e[2m
ITALIC			=	\e[3m
UNDERSCORE		=	\e[4m
REVERSE_VID		=	\e[7m
BLACK			=	\e[30m
RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
BLUE			=	\e[34m
MAGENTA			=	\e[35m
CYAN			=	\e[36m
WHITE			=	\e[37m
BLACK_BG		=	\e[40m
RED_BG			=	\e[41m
GREEN_BG		=	\e[42m
YELLOW_BG		=	\e[43m
BLUE_BG			=	\e[44m
MAGENTA_BG		=	\e[45m
CYAN_BG			=	\e[46m
WHITE_BG		=	\e[47m

#==================================== Rules ====================================

.PHONY : all clean fclean re debug debug_re

all: $(NAME)

$(NAME) : $(OBJS)
	@ld -r $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(COMPILE.c) -c $< -o $@

clean :
	@rm -rf $(NAME) $(OBJS_DIR)
fclean : clean

re: fclean all

debug : CFLAGS=-Wall -Wextra -g
debug : all

debug_re : fclean debug
