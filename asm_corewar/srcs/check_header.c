/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:38:17 by mmatime           #+#    #+#             */
/*   Updated: 2018/04/10 00:36:49 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	set_comment - si la ligne est .comment, la traite
*/

int			set_comment(char *str, t_header *header, int line_nb)
{
	int i;
	int start;
	int comment;

	i = 0;
	comment = 0;
	start = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) || ft_isalpha(str[i]))
			&& header->comment_is_set == 0)
			header_error(WRONG_INPUT, line_nb, str);
		else if ((ft_isdigit(str[i]) || ft_isalpha(str[i]))
			&& header->comment_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, str);
		else if (str[i] == COMMENT_CHAR && start == 0)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, str);
		else if (str[i] == '"' && start == 0)
			loop_comment(str, &i, &start, header);
		else if ((str[i] == COMMENT_CHAR || str[i] == WEIRD_CHAR)
			&& header->comment_is_set)
			comment = 1;
		i++;
	}
	return (1);
}

/*
**	set_name - si la ligne est .name, la traite
*/

int			set_name(char *str, t_header *header, int line_nb)
{
	int i;
	int start;
	int comment;

	i = 0;
	comment = 0;
	start = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) || ft_isalpha(str[i]))
			&& header->name_is_set == 0)
			header_error(WRONG_INPUT, line_nb, str);
		else if ((ft_isdigit(str[i]) || ft_isalpha(str[i]))
			&& header->name_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, str);
		else if (str[i] == COMMENT_CHAR && start == 0)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, str);
		else if (str[i] == '"' && start == 0)
			loop_name(str, &i, &start, header);
		else if ((str[i] == COMMENT_CHAR || str[i] == WEIRD_CHAR)
			&& header->name_is_set)
			comment = 1;
		i++;
	}
	return (1);
}

/*
**	line_is_point - si la ligne commence par (.), traitement
**	des données du header
*/

int			line_is_point(char *line, t_header *header, int line_nb)
{
	char	*str;

	if (!(line[0] && line[0] == CMD_CHAR))
		return (0);
	if (ft_strnequ(line, NAME_CMD_STRING, 5) && !header->name_is_set)
	{
		str = ft_strsub(line, 5, ft_strlen(line) - 5);
		str = epur_str_beginning(str);
		if (set_name(str, header, line_nb))
		{
			ft_strdel(&str);
			return (1);
		}
	}
	else if (ft_strnequ(line, COMMENT_CMD_STRING, 8) && !header->comment_is_set)
	{
		str = ft_strsub(line, 8, ft_strlen(line) - 8);
		str = epur_str_beginning(str);
		if (set_comment(str, header, line_nb))
		{
			ft_strdel(&str);
			return (1);
		}
	}
	return (0);
}

/*
** CHECK_HEADER - fonction qui lit le fichier ligne par ligne
** pour y trouver et set un header
*/

int			check_header(int fd, t_header *header)
{
	int		line_nb;
	char	*line;

	header_init(header);
	line_nb = 0;
	line = NULL;
	while (!header_is_set(header) && get_next_line(fd, &line, 100) > 0)
	{
		line_nb++;
		if (header->waiting_next_line)
		{
			add_to_header(line, header, line_nb);
			continue ;
		}
		line = epur_str_beginning(line);
		if (!line || *line == COMMENT_CHAR || *line == WEIRD_CHAR)
			continue ;
		else if (line_is_point(line, header, line_nb))
			continue ;
		header_error(WRONG_INPUT, line_nb, line);
	}
	if (!header_is_set(header))
		header_error(WRONG_HEADER, line_nb, line);
	free(line);
	return (line_nb);
}
