/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:38:17 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/08 10:12:05 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		char_is_valid(char c)
{
	if (c == ' ' || c == '\t' || c == '#')
		return (1);
	return (0);
}

void	header_error(int error, int line_nb, char *str)
{
	if (error == QUOTE_MARK)
		ft_printf("Can't find quote mark on line %d\n", line_nb);
	else if (error == INVALID_CHAR_NAME)
		ft_printf("Can't write anything without sharp sign ('#') on line %d\n", line_nb);
	else if (error == WRONG_INPUT)
		ft_printf("Wrong input on line %d\n", line_nb);
	else if (error == COMMENT_NOT_IN_PLACE)
		ft_printf("Can't comment before %s input on line %d\n", str, line_nb);
	exit (1);
}

int		loop_name(int *i, char *line, t_head *head)
{
	int tmp;

	*i += 1;
	if (line[*i] && line[*i] == '"')
	{
		head->name_is_set = 1; // ca veut dire que name est valide mais ne comporte pas de nom
		return (1);
	}
	else
	{
		tmp = *i;
		while (line[*i] && line[*i] != '"')
			*i += 1;
		if (line[*i] == '"') // on a un commentaire valide et on le sauvegarde
		{
			head->name = ft_strsub(line, tmp, *i - tmp);
			head->name_is_set = 1;
			return (1);
		}
		return (0); // ca veut dire qu'il n'a pas trouvé la guillemet fermante, que le fichier est mauvais
	}
}

int		set_name(char *line, t_head *head, int line_nb)
{
	int i;
	int comment;

	i = 5;
	comment = 0;
	while (line[i])
	{
		if (line[i] == '#' && head->name_is_set)
			comment = 1;
		else if (line[i] == '#' && !head->name_is_set)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, ".name");
		if (line[i] == '"' && !head->name_is_set)
		{
			if (loop_name(&i, line, head))
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

int		loop_comment(int *i, char *line, t_head *head)
{
	int tmp;

	*i += 1;
	if (line[*i] && line[*i] == '"')
	{
		head->comment_is_set = 1; // ca veut dire que name est valide mais ne comporte pas de nom
		return (1);
	}
	else
	{
		tmp = *i;
		while (line[*i] && line[*i] != '"')
			*i += 1;
		if (line[*i] == '"') // on a un commentaire valide et on le sauvegarde
		{
			head->comment = ft_strsub(line, tmp, *i - tmp);
			head->comment_is_set = 1;
			return (1);
		}
		return (0); // ca veut dire qu'il n'a pas trouvé la guillemet fermante, que le fichier est mauvais
	}
}

int		set_comment(char *line, t_head *head, int line_nb)
{
	int i;
	int comment;

	i = 8;
	comment = 0;
	while (line[i])
	{
		if (line[i] == '#' && head->comment_is_set)
			comment = 1;
		else if (line[i] == '#' && !head->comment_is_set)
			header_error(COMMENT_NOT_IN_PLACE, line_nb, ".comment");
		if (line[i] == '"' && !head->comment_is_set)
		{
			if (loop_comment(&i, line, head))
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

int		line_is_point(char *line, t_head *head, int line_nb) //check si une ligne commence par un '.'
{
	int i;

	i = 0;
	if (line[0] && line[0] == '.')
	{
		if (ft_strnequ(line, NAME_CMD_STRING, 5) && set_name(line, head, line_nb)) // check si .name est bon et pas autre chose (..name ou .namm)
			return (1);
		else if (ft_strnequ(line, COMMENT_CMD_STRING, 8) && set_comment(line, head, line_nb)) // check si .comment est bon et pas autre chose (..comment ou .commenn)
			return (1);
	}
	return (0);
}

char	*epur_str(char *line) // supprime les espaces en debut de ligne
{
	int i;
	char *dest;

	i = 0;
	dest = NULL;
	while ((line[i] && line[i] == ' ') || (line[i] && line[i] == '\t'))
		i++;
	if (line[i])
		dest = ft_strsub(line, i, ft_strlen(line));
	free(line);
	return (dest);
}

int		name_comment_set(t_head *head)
{
	if (head->name_is_set == 1 && head->comment_is_set == 1)
		return (1);
	return (0);
}

void	init_set(t_head *head)
{
	head->name_is_set = 0;
	head->comment_is_set = 0;
	head->head_error = 0;
	head->comment = NULL;
	head->name = NULL;
}

int					check_header(int fd, char *line)
{
	t_head 	head;
	int		line_nb;
	//lecture des trois premiere lignes, Verification .name et .comment
	init_set(&head);
	line_nb = 0;
	while (get_next_line(fd, &line, 100) > 0 && !name_comment_set(&head)) // cette ft renvoit 1 si .name et .comment sont deja set
	{
		line = epur_str(line); // supprime les espaces en debut de ligne
		line_nb++;
		if (*line == COMMENT_CHAR) // si c'est un com, on l'ignore et on passe a la prochaine itération de GNL
			continue ;
		else if (line_is_point(line, &head, line_nb)) // verifie si c'est .name ou .comment
			continue ;
		else
		{
			header_error(WRONG_INPUT, line_nb, "");
			return (0);
		}
	}
	if (head.name)
		ft_printf("name = >%s<\n", head.name);
	if (head.comment)
		ft_printf("comment = >%s<\n", head.comment);
	return (1);
}
