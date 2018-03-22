/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:38:17 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/22 10:08:48 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		line_is_point(char *line, t_header *header, int line_nb) //check si une ligne commence par un '.'
{
	int i;

	i = 0;
	if (line[0] && line[0] == '.')
	{
		if (ft_strnequ(line, NAME_CMD_STRING, 5) && set_name(line, header, line_nb)) // check si .name est bon et pas autre chose (..name ou .namm)
			return (1);
		else if (ft_strnequ(line, COMMENT_CMD_STRING, 8) && set_comment(line, header, line_nb)) // check si .comment est bon et pas autre chose (..comment ou .commenn)
			return (1);
	}
	return (0);
}

int		header_is_set(t_header *header)
{
	if (!header->name_is_set || !header->comment_is_set)
		return (0);
	return (1);
}

int		check_header(int fd, t_header *header)
{
	int		line_nb;
	int i;
	char *line;

	i = 0;
	init_set(header);
	line_nb = 0;
	line = NULL;
	while (!header_is_set(header) && get_next_line(fd, &line, 100) > 0) // cette ft renvoit 1 si .name et .comment sont deja set
	{
		line = epur_str_beginning(line); // supprime les espaces en debut de ligne
		line_nb++;

//		printf("%d : %s\n", line_nb, line);
		if (*line == COMMENT_CHAR) // si c'est un com, on l'ignore et on passe a la prochaine itération de GNL
			continue ;
		else if (line_is_point(line, header, line_nb)) // verifie si c'est .name ou .comment
			continue ;
		else
			header_error(WRONG_INPUT, line_nb, "");
	}
	/*
	** TEST AFFICHAGE TEMPORAIRE
	*/
//	if (header->prog_name[0])
//		ft_printf("name = >%s<\n", header->prog_name);
//	if (header->comment[0])
//		ft_printf("comment = >%s<\n", header->comment);
	return (line_nb);
}
