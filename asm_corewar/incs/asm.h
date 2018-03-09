/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:40:17 by lmartin-          #+#    #+#             */
/*   Updated: 2018/02/15 18:40:23 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_set //ajout d'une petite structure (temporaire?) pour tester si .name et .comment sont bien set
{
	int name;
	int comment;
}				t_set;

int			main(int ac, char **av);
int			ft_read_file(int fd, char *file_name);

int		char_is_valid(char c);
int		set_name(char *line, t_set *set);
int		set_comment(char *line, t_set *set);
int		line_is_point(char *line, t_set *set);
char	*epur_str(char *line);
int		name_comment_set(t_set *set);
int		check_header(int fd, char *line);
char	*ft_binary_itoa(unsigned char c, int type);
char	*ft_strndup(char *file_name, int nb);
int		ft_write(char *file_name, unsigned char *tab);
#endif
