/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:44:39 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/14 21:09:44 by lgraham          ###   ########.fr       */
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

# define QUOTE_MARK 1
# define INVALID_CHAR_NAME 2
# define WRONG_INPUT 3
# define COMMENT_NOT_IN_PLACE 4
# define NAME_TOO_LONG 5
# define COMMENT_TOO_LONG 6

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

typedef struct		s_label
{
	char			*name;
	int				pos;
	int				type; // 1 for a call, 0 for a declaration.
	struct s_label	*next;
}					t_label;

/*
** HEADER DE OP.H
*/

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	int					name_is_set;
	int					comment_is_set;
	int					head_error;
}					t_header;

/*
** FONCTION MAIN
*/

int				main(int ac, char **av);
int				ft_read_file(int fd, char *file_name);

/*
** FONCTION HEADER
*/

int				check_header(int fd, char *line, t_header *header);
void			header_error(int error, int line_nb, char *str);
int				loop_name(int *i, char *line, t_header *header);
int				set_name(char *line, t_header *header, int line_nb);
int				loop_comment(int *i, char *line, t_header *header);
int				set_comment(char *line, t_header *header, int line_nb);
int				line_is_point(char *line, t_header *header, int line_nb);
void			init_set(t_header *header);
int				char_is_valid(char c);

/*
** FONCTION WRITE
*/

int				ft_write(char *file_name, unsigned char *tab, t_header *header);

/*
** FONCTION UTILITAIRE
*/

char			*epur_str_beginning(char *line);
char			*ft_binary_itoa(unsigned char c, int type);

#endif
