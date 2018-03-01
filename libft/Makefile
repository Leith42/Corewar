# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 01:13:53 by gudemare          #+#    #+#              #
#    Updated: 2018/03/01 18:30:29 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================== Project ===================================

NAME			=	libft.a

CC				=	clang
CFLAGS			=	-Wall -Wextra -Weverything -Wno-cast-qual -Werror

LIB_H_DIR		=	incs
LIB_HEADERS		=	libft.h
IFLAGS			=	-I $(LIB_H_DIR)

COMPILE.c		=	$(CC) $(CFLAGS) $(IFLAGS)

SRCS_DIR		=	srcs/
SRCS_LIST		=	\
					array/ft_arr_addstr.c \
					array/ft_arrcollapse.c \
					array/ft_arrcpy.c \
					array/ft_arrdel_size.c \
					array/ft_arrdelone.c \
					array/ft_arrdup.c \
					array/ft_arrextend.c \
					array/ft_arrlen.c \
					array/ft_arrnew.c \
					array/ft_arrnstr.c \
					array/ft_arrnstr_loc.c \
					array/ft_arrstr.c \
					array/ft_arrstr_loc.c \
					array/ft_free_arr.c \
					btree/ft_btree_apply_infix.c \
					btree/ft_btree_apply_prefix.c \
					btree/ft_btree_apply_suffix.c \
					btree/ft_btree_insert_data.c \
					btree/ft_btree_lvlcount.c \
					btree/ft_btree_nodenew.c \
					btree/ft_btree_search_data.c \
					btree/ft_btree_treedel.c \
					display/ft_putarr.c \
					display/ft_putarr_fd.c \
					display/ft_putchar.c \
					display/ft_putchar_fd.c \
					display/ft_putendl.c \
					display/ft_putendl_fd.c \
					display/ft_putnbr.c \
					display/ft_putnbr_fd.c \
					display/ft_putnendl.c \
					display/ft_putnendl_fd.c \
					display/ft_putnstr.c \
					display/ft_putnstr_fd.c \
					display/ft_putstr.c \
					display/ft_putstr_fd.c \
					display/ft_putwchar.c \
					display/ft_putwchar_fd.c \
					display/ft_putwnstr.c \
					display/ft_putwnstr_fd.c \
					io/ft_read.c \
					io/get_next_line.c \
					list/ft_lstdel.c \
					list/ft_lstdelone.c \
					list/ft_lstiter.c \
					list/ft_lstmap.c \
					list/ft_lstnew.c \
					list/ft_lstnew_copy.c \
					list/ft_lstpush_back.c \
					list/ft_lstpush_front.c \
					math/ft_abs.c \
					math/ft_isprime.c \
					math/ft_max.c \
					math/ft_max_pos.c \
					math/ft_min.c \
					math/ft_min_pos.c \
					math/ft_oom.c \
					math/ft_power.c \
					math/ft_sign.c \
					math/ft_sqrt.c \
					memory/ft_bzero.c \
					memory/ft_memalloc.c \
					memory/ft_memccpy.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c \
					memory/ft_memcpy.c \
					memory/ft_memdel.c \
					memory/ft_memdup.c \
					memory/ft_memmove.c \
					memory/ft_memrchr.c \
					memory/ft_memset.c \
					misc/ft_arg.c \
					misc/ft_assert.c \
					misc/ft_atoi.c \
					misc/ft_basename.c \
					misc/ft_dirname.c \
					misc/ft_is_whitespace.c \
					misc/ft_isalnum.c \
					misc/ft_isalpha.c \
					misc/ft_isascii.c \
					misc/ft_iscntrl.c \
					misc/ft_isdigit.c \
					misc/ft_isprint.c \
					misc/ft_ispunct.c \
					misc/ft_isspace.c \
					misc/ft_isxdigit.c \
					misc/ft_itoa.c \
					misc/ft_sort_inplace.c \
					misc/ft_swap.c \
					misc/ft_tolower.c \
					misc/ft_toupper.c \
					string/ft_exit.c \
					string/ft_get_word.c \
					string/ft_is_str_ws.c \
					string/ft_str_wordnb.c \
					string/ft_strcasecmp.c \
					string/ft_strcasestr.c \
					string/ft_strcat.c \
					string/ft_strchr.c \
					string/ft_strchr_count.c \
					string/ft_strchr_loc.c \
					string/ft_strchrnul.c \
					string/ft_strclr.c \
					string/ft_strcmp.c \
					string/ft_strcpy.c \
					string/ft_strdel.c \
					string/ft_strdup.c \
					string/ft_strequ.c \
					string/ft_strextend.c \
					string/ft_strextjoin.c \
					string/ft_striter.c \
					string/ft_striteri.c \
					string/ft_strjoin.c \
					string/ft_strlcat.c \
					string/ft_strlen.c \
					string/ft_strmap.c \
					string/ft_strmapi.c \
					string/ft_strncat.c \
					string/ft_strncmp.c \
					string/ft_strncpy.c \
					string/ft_strndup.c \
					string/ft_strnequ.c \
					string/ft_strnew.c \
					string/ft_strnstr.c \
					string/ft_strrchr.c \
					string/ft_strsplit.c \
					string/ft_strsplit_ws.c \
					string/ft_strstr.c \
					string/ft_strsub.c \
					string/ft_strtrim.c \
					string/get_next_word.c \
					string/wstring/ft_wcharsize.c \
					string/wstring/ft_wmemset.c \
					string/wstring/ft_wstrdup.c \
					string/wstring/ft_wstrlen.c \
					string/wstring/ft_wstrncpy.c \
					string/wstring/ft_wstrsize.c
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

SUBPROJECTS_LIST=	ft_printf/
SUBPROJECTS		=	$(addprefix $(SRCS_DIR), $(SUBPROJECTS_LIST))
SUBPROJECTS_OBJS=	srcs/ft_printf/ft_printf.o

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

.PHONY : all norme clean fclean re debug debug_re $(SUBPROJECTS)

all: $(NAME)

$(NAME) : $(OBJS) $(SUBPROJECTS)
	@ar rc $(NAME) $(OBJS) $(SUBPROJECTS_OBJS)
	@ranlib $(NAME)
	@printf "$(GREEN)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) successfully compiled.$(END_GRAPHICS)\n"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR) $(OBJS_DIR){array,btree,display,io,list,math,memory,misc,string,string/wstring}
	@printf "\e[K$(CYAN)Compiling $(BOLD)$(notdir $<)$(END_GRAPHICS)$(CYAN) ...\n\e[A$(END_GRAPHICS)"
	@$(COMPILE.c) -c $< -o $@

$(SUBPROJECTS) :
	@make -C $@

clean :
	@rm -rf $(OBJS_DIR)
	@for dir in $(SUBPROJECTS); do \
		make -C $$dir clean; \
	done
	@printf "$(YELLOW)Library $(NAME)'s objects files have been removed.$(END_GRAPHICS)\n"
fclean :
	@rm -rf $(NAME) $(OBJS_DIR)
	@for dir in $(SUBPROJECTS); do \
		make -C $$dir fclean; \
	done
	@printf "$(YELLOW)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(YELLOW) and its projects files have been removed.$(END_GRAPHICS)\n"

re: fclean all

#================================ Personal Rules ===============================

norme :
	@if type "norminette" &> /dev/null ; then \
		printf "$(BLUE)$(BOLD)[ ] $(NAME)$(END_GRAPHICS)\n\e[A" && \
		norminette $(SRCS) $(LIB_H_DIR) | grep -v -B 1 "^Norme: " || printf "$(GREEN)[✔]\n$(END_GRAPHICS)" ; \
	else \
		printf "$(RED)Norminette not installed, cannot check norm.\n$(END_GRAPHICS)" ; \
	fi


debug : CFLAGS=-Wall -Wextra -g
debug : all
	@printf "\e[K$(GREEN)Library $(BOLD)$(NAME)$(END_GRAPHICS)$(GREEN) has successfully compiled $(YELLOW)(with debug symbols).$(END_GRAPHICS)\n"

debug_re : fclean debug
