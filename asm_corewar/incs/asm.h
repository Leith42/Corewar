/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:40:17 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/09 20:30:56 by mmatime          ###   ########.fr       */
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

typedef struct s_head //ajout d'une petite structure (temporaire?) pour tester si .name et .comment sont bien set
{
	int name_is_set;
	int comment_is_set;
	char *name;
	char *comment;
	int head_error;
}				t_head;

int			main(int ac, char **av);
int			ft_read_file(int fd, char *file_name);

int		char_is_valid(char c);
int		set_name(char *line, t_head *head, int line_nb);
int		set_comment(char *line, t_head *head, int line_nb);
int		line_is_point(char *line, t_head *head, int line_nb);
char	*epur_str(char *line);
int		name_comment_set(t_head *head);
int		check_header(int fd, char *line);
char	*ft_binary_itoa(unsigned char c, int type);
int		ft_write(char *file_name, unsigned char *tab);
#endif
