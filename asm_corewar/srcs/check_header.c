/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:38:17 by mmatime           #+#    #+#             */
/*   Updated: 2018/04/05 04:27:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	line_is_point - si la ligne commence par (.), traitement
**	des données du header
*/

void		loop_name_(char *str, int *i, int *start, t_header *header)
{
	*i += 1;
	*start = 1;
	while (str[*i] && str[*i] != '"')
	{
		if (header->name_length > PROG_NAME_LENGTH)
			header_error(NAME_TOO_LONG, 0, "");
		header->prog_name[header->name_length++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '"')
		header->name_is_set = 1;
	else
	{
		if (header->name_length < PROG_NAME_LENGTH)
			header->prog_name[header->name_length++] = '\n';
		*i -= 1;
		header->waiting_next_line = 1;	
	}
}

void		loop_comment_(char *str, int *i, int *start, t_header *header)
{
	*i += 1;
	*start = 1;
	while (str[*i] && str[*i] != '"')
	{
		if (header->comment_length > COMMENT_LENGTH)
			header_error(COMMENT_TOO_LONG, 0, "");
		header->comment[header->comment_length++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '"')
		header->comment_is_set = 1;
	else
	{
		if (header->comment_length < COMMENT_LENGTH)
			header->comment[header->comment_length++] = '\n';
		*i -= 1;
		header->waiting_next_line = 1;	
	}
}

int			set_comment_(char *str, t_header *header, int line_nb)
{
	int i;
	int start;
	int comment;

	i = 0;
	comment = 0;
	start = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) || ft_isalpha(str[i])) && header->comment_is_set == 0)
			header_error(WRONG_INPUT, line_nb, "");
		else if ((ft_isdigit(str[i]) || ft_isalpha(str[i])) && header->comment_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, NAME_CMD_STRING);
		else if (str[i] == COMMENT_CHAR && start == 0)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, NAME_CMD_STRING);
		else if (str[i] == '"' && start == 0)
			loop_comment_(str, &i, &start, header);
		else if ((str[i] == COMMENT_CHAR || str[i] == WEIRD_CHAR) && header->comment_is_set)
			comment = 1;
		i++;
	}
	return (1);
}

int			set_name_(char *str, t_header *header, int line_nb)
{
	int i;
	int start;
	int comment;

	i = 0;
	comment = 0;
	start = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) || ft_isalpha(str[i])) && header->name_is_set == 0)
			header_error(WRONG_INPUT, line_nb, "");
		else if ((ft_isdigit(str[i]) || ft_isalpha(str[i])) && header->name_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, NAME_CMD_STRING);
		else if (str[i] == COMMENT_CHAR && start == 0)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, NAME_CMD_STRING);
		else if (str[i] == '"' && start == 0)
			loop_name_(str, &i, &start, header);
		else if ((str[i] == COMMENT_CHAR || str[i] == WEIRD_CHAR) && header->name_is_set)
			comment = 1;
		i++;
	}
	return (1);
}

static int	line_is_point(char *line, t_header *header, int line_nb)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	if (line[0] && line[0] == CMD_CHAR)
	{
		if (ft_strnequ(line, NAME_CMD_STRING, 5))
		{
			str = ft_strsub(line, 5, ft_strlen(line) - 5);
			str = epur_str_beginning(str);
			if (set_name_(str, header, line_nb))
				return (1);
		}
		else if (ft_strnequ(line, COMMENT_CMD_STRING, 8))
		{
			str = ft_strsub(line, 8, ft_strlen(line) - 8);
			str = epur_str_beginning(str);
			if (set_comment_(str, header, line_nb))
				return (1);
		}
	}
	return (0);
}

/*
** header_is_set - fonction qui vérifie a chaque GNL
** si ce que l'on recherche est set
*/

static int	header_is_set(t_header *header)
{
	if (!header->name_is_set || !header->comment_is_set)
		return (0);
	return (1);
}

void	add_to_name(char *line, t_header *header, int line_nb)
{
	int i;
	int comment;

	i = 0;
	comment = 0;
	if (!line)
	{
		if (header->name_length < PROG_NAME_LENGTH)
		{
			header->prog_name[header->name_length++] = '\n';
			return ;
		}
		header_error(NAME_TOO_LONG, 0, "");
	}
	while (line[i])
	{
		if ((ft_isdigit(line[i]) || ft_isalpha(line[i])) && header->name_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, NAME_CMD_STRING);
		else if ((line[i] == COMMENT_CHAR || line[i] == WEIRD_CHAR) && header->name_is_set)
			comment = 1;
		if (header->name_length > PROG_NAME_LENGTH)
			header_error(NAME_TOO_LONG, 0, "");
		if (line[i] != '"' && header->name_is_set == 0)
			header->prog_name[header->name_length++] = line[i];
		else
		{
			header->name_is_set = 1;
			header->waiting_next_line = 0;
		}
		i++;
	}
	if (header->name_is_set == 0)
	{
		if (header->name_length < PROG_NAME_LENGTH)
			header->prog_name[header->name_length++] = '\n';
	}
	//printf("on est sorti et .name est set a %d et waiting est a %d\n", header->name_is_set, header->waiting_next_line);
}

void	add_to_comment(char *line, t_header *header, int line_nb)
{
	int i;
	int comment;

	i = 0;
	comment = 0;
	if (!line)
	{
		if (header->comment_length < COMMENT_LENGTH)
		{
			header->comment[header->name_length++] = '\n';
			return ;
		}
		header_error(COMMENT_TOO_LONG, 0, "");
	}
	while (line[i])
	{
		if ((ft_isdigit(line[i]) || ft_isalpha(line[i])) && header->comment_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, NAME_CMD_STRING);
		else if ((line[i] == COMMENT_CHAR || line[i] == WEIRD_CHAR) && header->comment_is_set)
			comment = 1;
		if (header->comment_length > COMMENT_LENGTH)
			header_error(COMMENT_TOO_LONG, 0, "");
		if (line[i] != '"' && header->comment_is_set == 0)
			header->comment[header->comment_length++] = line[i];
		else
		{
			header->comment_is_set = 1;
			header->waiting_next_line = 0;
		}
		i++;
	}
	if (header->comment_is_set == 0)
	{
		if (header->comment_length < COMMENT_LENGTH)
			header->comment[header->comment_length++] = '\n';
	}
}

void	add_to_header(char *line, t_header *header, int line_nb)
{
	if (header->name_is_set == 0)
		add_to_name(line, header, line_nb);
	else
		add_to_comment(line, header, line_nb);
}
/*
** CHECK_HEADER - fonction qui lit le fichier ligne par ligne
** pour y trouver et set un header
*/

int			check_header(int fd, t_header *header)
{
	int		line_nb;
	int		i;
	char	*line;

	i = 0;
	init_set(header);
	line_nb = 0;
	line = NULL;
	while (!header_is_set(header) && get_next_line(fd, &line, 100) > 0)
	{
		line = epur_str_beginning(line);
		line_nb++;
		if (header->waiting_next_line)
		{	
			add_to_header(line, header, line_nb);
			continue ;
		}
		else if (!line || *line == COMMENT_CHAR || *line == WEIRD_CHAR)
			continue ;
		else if (line_is_point(line, header, line_nb))
			continue ;
		header_error(WRONG_INPUT, line_nb, "");
	}
	if (!header_is_set(header))
		header_error(WRONG_HEADER, line_nb, "");
	return (line_nb);
}
