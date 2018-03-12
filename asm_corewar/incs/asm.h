/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:44:39 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/10 18:49:30 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

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

typedef struct	s_head
{
	int			name_is_set;
	int			comment_is_set;
	char		*name;
	char		*comment;
	int			head_error;
}				t_head;

/*
** FONCTION MAIN
*/

int				main(int ac, char **av);
int				ft_read_file(int fd, char *file_name);

/*
** FONCTION HEADER
*/

int				check_header(int fd, char *line);
void			header_error(int error, int line_nb, char *str);
int				loop_name(int *i, char *line, t_head *head);
int				set_name(char *line, t_head *head, int line_nb);
int				loop_comment(int *i, char *line, t_head *head);
int				set_comment(char *line, t_head *head, int line_nb);
int				line_is_point(char *line, t_head *head, int line_nb);
void			init_set(t_head *head);
int				char_is_valid(char c);

/*
** FONCTION WRITE
*/

int				ft_write(char *file_name, unsigned char *tab);

/*
** FONCTION UTILITAIRE
*/

char			*epur_str_beginning(char *line);
char			*ft_binary_itoa(unsigned char c, int type);

#endif
