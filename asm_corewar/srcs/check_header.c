/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:38:17 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/10 18:56:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	header_error(int error, int line_nb, char *str)
{
	if (error == QUOTE_MARK)
		ft_printf("Can't find quote mark on line %d\n", line_nb);
	else if (error == INVALID_CHAR_NAME)
		ft_printf("Can't write anything without sharp sign ('#') on line %d\n",
		 line_nb);
	else if (error == WRONG_INPUT)
		ft_printf("Wrong input on line %d\n", line_nb);
	else if (error == COMMENT_NOT_IN_PLACE)
		ft_printf("Can't comment before %s input on line %d\n", str, line_nb);
	else if (error == NAME_TOO_LONG)
		ft_printf("Champion name too long (Max length 128)\n");
	else if (error == COMMENT_TOO_LONG)
		ft_printf("Champion comment too long (Max length 2048)\n");
	exit(1);
}

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

void	init_set(t_header *header)
{
	header->name_is_set = 0;
	header->comment_is_set = 0;
	header->head_error = 0;
	memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
	memset(header->comment, 0, COMMENT_LENGTH + 1);
}

int		check_header(int fd, char *line, t_header *header)
{
	int		line_nb;
	int i;

	i = 0;
	init_set(header);
	line_nb = 0;
	while (get_next_line(fd, &line, 100) > 0 && (header->name_is_set != 1
	|| header->comment_is_set != 1)) // cette ft renvoit 1 si .name et .comment sont deja set
	{
		line = epur_str_beginning(line); // supprime les espaces en debut de ligne
		line_nb++;
		if (*line == COMMENT_CHAR) // si c'est un com, on l'ignore et on passe a la prochaine itération de GNL
			continue ;
		else if (line_is_point(line, header, line_nb)) // verifie si c'est .name ou .comment
			continue ;
		else
			header_error(WRONG_INPUT, line_nb, "");
	}
	/*
	** TEST TEMPORAIRE
	*/
	if (header->prog_name[0])
		ft_printf("name = >%s<\n", header->prog_name);
	if (header->comment[0])
		ft_printf("comment = >%s<\n", header->comment);
	return (1);
}
