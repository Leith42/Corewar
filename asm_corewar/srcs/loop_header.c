/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:49:21 by mmatime           #+#    #+#             */
/*   Updated: 2018/04/09 23:02:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	add_to_name - stock le contenu de la ligne jusqu'a trouver "
**	cette fonction ajoute au name deja existant sur le précédent GNL
*/

void	add_to_name(char *line, t_header *header, int line_nb)
{
	int i;
	int comment;

	i = -1;
	comment = 0;
	while (line && line[++i])
	{
		if ((ft_isdigit(line[i]) || ft_isalpha(line[i]))
			&& header->name_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, line);
		else if ((line[i] == COMMENT_CHAR || line[i] == WEIRD_CHAR)
			&& header->name_is_set)
			comment = 1;
		if (header->name_length > PROG_NAME_LENGTH)
			header_error(NAME_TOO_LONG, 0, line);
		if (line[i] != '"' && header->name_is_set == 0)
			header->prog_name[header->name_length++] = line[i];
		else
		{
			header->name_is_set = 1;
			header->waiting_next_line = 0;
		}
	}
	if (header->name_is_set == 0)
		add_backslash_to_name(header, line);
}

/*
**	add_to_comment - stock le contenu de la ligne jusqu'a trouver "
**	cette fonction ajoute au comment deja existant sur le précédent GNL
*/

void	add_to_comment(char *line, t_header *header, int line_nb)
{
	int i;
	int comment;

	i = -1;
	comment = 0;
	while (line && line[++i])
	{
		if ((ft_isdigit(line[i]) || ft_isalpha(line[i]))
			&& header->comment_is_set && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, line);
		else if ((line[i] == COMMENT_CHAR || line[i] == WEIRD_CHAR)
				&& header->comment_is_set)
			comment = 1;
		if (header->comment_length > COMMENT_LENGTH)
			header_error(COMMENT_TOO_LONG, 0, line);
		if (line[i] != '"' && header->comment_is_set == 0)
			header->comment[header->comment_length++] = line[i];
		else
		{
			header->comment_is_set = 1;
			header->waiting_next_line = 0;
		}
	}
	if (header->comment_is_set == 0)
		add_backslash_to_comment(header, line);
}

/*
**	loop_name - stock le contenu de la ligne jusqu'a trouver "
*/

void	loop_name(char *str, int *i, int *start, t_header *header)
{
	*i += 1;
	*start = 1;
	while (str[*i] && str[*i] != '"')
	{
		if (header->name_length > PROG_NAME_LENGTH)
			header_error(NAME_TOO_LONG, 0, str);
		header->prog_name[header->name_length++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '"')
		header->name_is_set = 1;
	else
	{
		add_backslash_to_name(header, str);
		*i -= 1;
		header->waiting_next_line = 1;
	}
}

/*
**	loop_comment - stock le contenu de la ligne jusqu'a trouver "
*/

void	loop_comment(char *str, int *i, int *start, t_header *header)
{
	*i += 1;
	*start = 1;
	while (str[*i] && str[*i] != '"')
	{
		if (header->comment_length > COMMENT_LENGTH)
			header_error(COMMENT_TOO_LONG, 0, str);
		header->comment[header->comment_length++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '"')
		header->comment_is_set = 1;
	else
	{
		add_backslash_to_comment(header, str);
		*i -= 1;
		header->waiting_next_line = 1;
	}
}
