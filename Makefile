# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 01:34:51 by gudemare          #+#    #+#              #
#    Updated: 2018/03/05 16:06:13 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================================== Project ===================================

LIBFT		=	libft/libft.a
NAME_ASM	=	asm
NAME_VM		=	corewar

LIBFT_DIR	=	libft/
ASM_DIR		=	asm_corewar/
VM_DIR		=	vm/

#==================================== Rules ====================================

.PHONY : all clean fclean re

all: $(LIBFT) $(NAME_ASM) $(NAME_VM)

$(LIBFT) :
	@make -C $(LIBFT_DIR) -j8

$(NAME_ASM) : $(LIBFT)
	@make -C $(ASM_DIR) -j8

$(NAME_VM) : $(LIBFT)
	@make -C $(VM_DIR) -j8

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(ASM_DIR) clean
	@make -C $(VM_DIR) clean

fclean :
	@make -C $(LIBFT_DIR) fclean
	@make -C $(ASM_DIR) fclean
	@make -C $(VM_DIR) fclean

re:
	@make -C $(LIBFT_DIR) re
	@make -C $(ASM_DIR) re
	@make -C $(VM_DIR) re
