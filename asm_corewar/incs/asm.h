/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:44:39 by mmatime           #+#    #+#             */
/*   Updated: 2018/04/05 03:39:52 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

enum				e_error
{
	QUOTE_MARK,
	INVALID_CHAR_NAME,
	WRONG_INPUT,
	WRONG_HEADER,
	COMMENT_NOT_IN_PLACE,
	NAME_TOO_LONG,
	COMMENT_TOO_LONG,
	INVALID_INST,
	INVALID_PARAMS,
	TOO_MANY_PARAMS,
	WRONG_REGISTER,
	SYNTAX_ERROR
};

/*
** LISTE INSTRUCTION
*/

typedef struct		s_lst_op
{
	unsigned char	op[12];
	int				label_pos[4];
	int				label_nb;
	int				pos;
	int				line_nb;
	struct s_lst_op	*next;
}					t_lst_op;

/*
** STRUCT OP.C
*/

typedef struct		s_op
{
	char			*name;
	unsigned short	param_nb;
	unsigned short	param_type[3];
	unsigned short	opcode;
	unsigned short	cycle_nb;
	char			*description;
	bool			ocp;
	bool			addr_or_nb;
}					t_op;

extern t_op			g_op_tab[17];

/*
** LISTE LABEL
** type is 0 for a declaration, 1 for a call
*/

typedef struct		s_label
{
	char			*name;
	int				oct;
	int				line;
	int				type;
	int				is_set;
	struct s_label	*next;
}					t_label;

/*
** HEADER DE OP.H
*/

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
	int				name_is_set;
	int				comment_is_set;
	int				head_error;
	int				name_length;
	int				comment_length;
	int				waiting_next_line;
}					t_header;

/*
** FONCTION MAIN
*/

int					main(int ac, char **av);
int					ft_read_file(int fd, char *file_name);

/*
** FONCTION HEADER
*/

int					set_comment(char *str, t_header *header, int line_nb);
int					set_name(char *str, t_header *header, int line_nb);
int					line_is_point(char *line, t_header *header, int line_nb);
int					check_header(int fd, t_header *header);
void				add_to_name(char *line, t_header *header, int line_nb);
void				add_to_comment(char *line, t_header *header, int line_nb);
void				loop_name(char *str, int *i, int *start, t_header *header);
void				loop_comment(char *str, int *i, int *start, t_header *header);
void				add_backslash_to_name(t_header *header, char *str);
void				add_backslash_to_comment(t_header *header, char *str);
int					header_is_set(t_header *header);
void				add_to_header(char *line, t_header *header, int line_nb);
void				header_init(t_header *header);
void				header_error(enum e_error error, int line_nb, char *str);

/*
** FONCTION INSTRUCTION
*/

t_lst_op			*init_lst(int ln);
int					inst_error(enum e_error error, int line_nb, char *str);
int					check_inst(t_lst_op *lst, int fd);

/*
** FONCTION LABEL
*/

int					double_check_label(t_label *label);
int					find_match(t_label *label, char *str);
t_label				*set_label(char **inst, t_label *label_list,
					int pos, int line);
int					check_label_char(char *str);
int					check_label(char **inst);
void				aff_label(t_label *label_lst);
void				oct_count(char **inst, int pos, t_label *label);
int					oct_prec(int pos, char **str);
void				calc_dist_label(t_label *label, t_lst_op *lst);
void				replace_dist(t_label *label, t_lst_op *lst);
void				fill_label_pos(int *tab, int pos);
int					fill_label(t_label *label, t_lst_op *lst);

/*
** FONCTION WRITE
*/

int					ft_write(char *file_name, t_lst_op *lst, t_header *header);

/*
** FONCTION UTILITAIRE
*/

t_lst_op			*rmp_param(int param, t_lst_op *lst,
					int dir_size, int label);
int					param_type(char *param);
char				**ft_split_inst(char *inst);
char				*epur_str_beginning(char *line);
void				free_lst(t_lst_op *lst);
void				free_label(t_label *label);

#endif

