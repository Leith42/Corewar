# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 01:34:51 by gudemare          #+#    #+#              #
#    Updated: 2018/03/10 18:26:37 by mmatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================== Project ===================================

NAME			=	../asm

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror #-Weverything -Wno-padded -Wno-missing-noreturn
LIB_H_DIR		=	../libft/incs
PROJECT_H_DIR	=	incs/
IFLAGS			=	-I $(LIB_H_DIR) -I $(PROJECT_H_DIR)

COMPILE.c		=	$(CC) $(CFLAGS) $(IFLAGS)

LIBFT			=	../libft/libft.a
LFLAGS			=	-lft -L../libft

SRCS_DIR		=	srcs/
SRCS_LIST		=	\
					check_header.c \
					main.c \
					read.c \
					loop_header.c \
					write.c \
					utils.c \
					op.c \
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

.PHONY : all norme clean fclean re debug debug_re

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(COMPILE.c) $(LFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Executable $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) has been created.$(END_GRAPHICS)\n"

$(LIBFT) :
	@make -C ../libft -j8

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR) $(OBJS_DIR)/{parsing,run,op_func}
	@printf "\e[K$(CYAN)Compiling $(BOLD)$(notdir $<)$(END_GRAPHICS)$(CYAN) ...\n\e[A$(END_GRAPHICS)"
	@$(COMPILE.c) -c $< -o $@

clean :
	@rm -rf $(OBJS_DIR)
	@printf "$(YELLOW)Executable $(BOLD)$(NAME)$(END_GRAPHICS)$(YELLOW)'s objects files have been removed.$(END_GRAPHICS)\n"
fclean :
	@rm -rf $(NAME) $(OBJS_DIR)
	@printf "$(YELLOW)Executable $(BOLD)$(NAME)$(END_GRAPHICS)$(YELLOW) and its objects files have been removed.$(END_GRAPHICS)\n"

re: fclean all

#================================ Personal Rules ===============================

norme :
	@if type "norminette" &> /dev/null ; then \
		printf "Checking Norm...\n"; \
		printf "$(BLUE)$(BOLD)[ ] $(NAME)$(END_GRAPHICS)\n\e[A" && \
		norminette $(SRCS) $(PROJECT_H_DIR) | grep -v -B 1 "^Norme: " || printf "$(GREEN)[✔]\n$(END_GRAPHICS)" ; \
	else \
		printf "$(RED)Norminette not installed, cannot check norm.\n$(END_GRAPHICS)" ; \
	fi

debug : CFLAGS=-Wall -Wextra -g
debug : all
	@printf "\e[K$(GREEN)Executable $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) has successfully compiled $(YELLOW)(with debug symbols).$(END_GRAPHICS)\n"

debug_re : fclean debug
