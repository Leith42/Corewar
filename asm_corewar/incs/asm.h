/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:44:39 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/20 08:46:12 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "get_next_line.h"
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
	COMMENT_NOT_IN_PLACE,
	NAME_TOO_LONG,
	COMMENT_TOO_LONG,
	INVALID_INST,
	INVALID_PARAMS,
	TOO_MANY_PARAMS,
	WRONG_REGISTER
};

/*
** LISTE INSTRUCTION
*/

typedef struct		s_lst_op
{
	unsigned char	op[12];
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
*/

typedef struct		s_label
{
	char			*name;
	int				pos;
	int				oct;
	int				oct_tmp;
	int				line;
	int				place;
	int				res;
	int				type; // 0 for a declaration, 1 for a call;
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
}					t_header;

/*
** FONCTION MAIN
*/

int					main(int ac, char **av);
int					ft_read_file(int fd, char *file_name);

/*
** FONCTION HEADER
*/

int					check_header(int fd, t_header *header);
void				header_error(enum e_error error, int line_nb, char *str);
int					loop_name(int *i, char *line, t_header *header);
int					set_name(char *line, t_header *header, int line_nb);
int					loop_comment(int *i, char *line, t_header *header);
int					set_comment(char *line, t_header *header, int line_nb);
int					line_is_point(char *line, t_header *header, int line_nb);
void				init_set(t_header *header);
int					char_is_valid(char c);

/*
** FONCTION INSTRUCTION
*/

t_lst_op			*init_lst(int nb);
int					inst_error(enum e_error error, int line_nb, char *str);
int					get_params(char	**inst, t_lst_op *lst, int opc);
int					check_params(char **inst, int opcode, int line_nb);
unsigned char		get_ocp(char **inst);
int					get_inst(char **inst, t_lst_op *lst);
int					check_inst(t_lst_op *lst, int fd, int lnbr);


/*
** FONCTION LABEL
*/

int					double_check_label(t_label *label);
int					find_match(t_label *label, char *str);
t_label				*check_label(char **inst, t_label *label, int pos, int p);
int					check_label_char(char *str);
t_label				*add_to_lst(t_label *label_list, t_label *new);
void				set_label_name(t_label *new, char *src, int p);
void				aff_label(t_label *label_lst);
void				oct_count(char **inst, int pos, t_label *label);
int					oct_prec(int pos, char **str, int nb);
void				calc_dist_label(t_label *label, t_lst_op *lst);
void				replace_dist(t_label *label, t_lst_op *lst);

/*
** FONCTION WRITE
*/

int					ft_write(char *file_name, unsigned char *tab, t_header *header);

/*
** FONCTION UTILITAIRE
*/

t_lst_op			*rmp_param(int param, t_lst_op *lst, int dir_size);
int					param_type(char *param);
char				**ft_split_inst(char *inst);
char				*epur_str_beginning(char *line);
char				*ft_binary_itoa(unsigned char c, int type);

#endif
