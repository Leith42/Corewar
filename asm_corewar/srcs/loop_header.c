/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:49:21 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/22 10:07:56 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		char_is_valid(char c)
{
	if (c == ' ' || c == '\t' || c == '#')
		return (1);
	return (0);
}

int		loop_name(int *i, char *line, t_header *header)
{
	int tmp;
	char *name_tmp;

	*i += 1;
	if (line[*i] && line[*i] == '"')
	{
		header->name_is_set = 1; // ca veut dire que name est valide mais ne comporte pas de nom
		return (1);
	}
	else
	{
		tmp = *i;
		while (line[*i] && line[*i] != '"')
			*i += 1;
		if (line[*i] == '"') // on a un commentaire valide et on le sauvegarde
		{
			if ((*i - tmp) > PROG_NAME_LENGTH)
				header_error(NAME_TOO_LONG, 0, "");
			name_tmp = ft_strsub(line, tmp, (*i - tmp));
			ft_memcpy(header->prog_name, name_tmp, ft_strlen(name_tmp));
			free(name_tmp);
			header->name_is_set = 1;
			return (1);
		}
		return (0); // ca veut dire qu'il n'a pas trouvé la guillemet fermante, que le fichier est mauvais
	}
}

int		set_name(char *line, t_header *header, int line_nb)
{
	int i;
	int comment;

	i = 5;
	comment = 0;
	while (line[i])
	{
		if (line[i] == '#' && header->name_is_set)
			comment = 1;
		else if (line[i] == '#' && !header->name_is_set)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, ".name");
		if (line[i] == '"' && !header->name_is_set)
		{
			if (loop_name(&i, line, header))
			{
				i++;
				continue ;
			}
			header_error(QUOTE_MARK, line_nb, ".name");
		}
		if (!char_is_valid(line[i]) && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, ".name");
		i++;
	}
	return (1);
}

int		loop_comment(int *i, char *line, t_header *header)
{
	int tmp;
	char *comment_tmp;

	*i += 1;
	if (line[*i] && line[*i] == '"')
	{
		header->comment_is_set = 1; // ca veut dire que name est valide mais ne comporte pas de nom
		return (1);
	}
	else
	{
		tmp = *i;
		while (line[*i] && line[*i] != '"')
			*i += 1;
		if (line[*i] == '"') // on a un commentaire valide et on le sauvegarde
		{	
			if ((*i - tmp) > COMMENT_LENGTH)
				header_error(COMMENT_TOO_LONG, 0, "");
			comment_tmp = ft_strsub(line, tmp, *i - tmp);
			ft_memcpy(header->comment, comment_tmp, ft_strlen(comment_tmp));
			free(comment_tmp);
			header->comment_is_set = 1;
			return (1);
		}
		return (0); // ca veut dire qu'il n'a pas trouvé la guillemet fermante, que le fichier est mauvais
	}
}

int		set_comment(char *line, t_header *header, int line_nb)
{
	int i;
	int comment;

	i = 8;
	comment = 0;
	while (line[i])
	{
		if (line[i] == '#' && header->comment_is_set)
			comment = 1;
		else if (line[i] == '#' && !header->comment_is_set)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, ".comment");
		if (line[i] == '"' && !header->comment_is_set)
		{
			if (loop_comment(&i, line, header))
			{
				i++;
				continue ;
			}
			header_error(QUOTE_MARK, line_nb, ".comment");
		}
		if (!char_is_valid(line[i]) && comment == 0)
			header_error(INVALID_CHAR_NAME, line_nb, ".comment");
		i++;
	}
	return (1);
}
