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

int		set_name(char *line, t_set *set)
{
	int i;
	int tmp;
	int j;
	char *name;
	int comment;

	i = 5;
	j = 0;
	comment = 0;
	name = NULL;
	while (line[i])
	{
		if (line[i] == '#')
		{
			if (set->name)
				comment = 1;
			else
				return (0);//ca veut dire qu'on veut deja ecrire un commentaire avant d'avoir mis un nom valide
		}
		if (line[i] == '"' && !set->name)
		{
			i++;
			if (line[i] && line[i] == '"')
				set->name = 1; // ca veut dire que name est valide mais ne comporte pas de nom
			else
			{
				tmp = i;
				while (line[i] && line[i] != '"')
				{
					i++;
					j++;
				}
				if (line[i] == '"') // on a un nom valide et on le sauvegarde
				{
					name = ft_strsub(line, tmp, j);
					set->name = 1;
					i++;
				}
				else
					return (0); // ca veut dire qu'il n'a pas trouvé la guillemet fermante, que le fichier est mauvais
			}
		}
		if (!char_is_valid(line[i]) && comment == 0)
			return (0);
		i++;
	}
	return (1);
}

int		set_comment(char *line, t_set *set)
{
	int i;
	int tmp;
	int j;
	char *name;
	int comment;

	i = 8;
	j = 0;
	comment = 0;
	name = NULL;
	while (line[i])
	{
		if (line[i] == '#')
		{
			if (set->comment)
				comment = 1;
			else
				return (0);//ca veut dire qu'on veut deja ecrire un commentaire avant d'avoir mis un nom valide
		}
		if (line[i] == '"' && !set->comment)
		{
			i++;
			if (line[i] && line[i] == '"')
				set->comment = 1; // ca veut dire que name est valide mais ne comporte pas de nom
			else
			{
				tmp = i;
				while (line[i] && line[i] != '"')
				{
					i++;
					j++;
				}
				if (line[i] == '"') // on a un commentaire valide et on le sauvegarde
				{
					name = ft_strsub(line, tmp, j);
					set->comment = 1;
					i++;
				}
				else
					return (0); // ca veut dire qu'il n'a pas trouvé la guillemet fermante, que le fichier est mauvais
			}
		}
		if (!char_is_valid(line[i]) && comment == 0)
			return (0);
		i++;
	}
	return (1);
}

int		line_is_point(char *line, t_set *set) //check si une ligne commence par un '.'
{
	int i;

	i = 0;
	if (line[0] && line[0] == '.')
	{
		if (ft_strnequ(line, NAME_CMD_STRING, 5) && set_name(line, set)) // check si .name est bon et pas autre chose (..name ou .namm)
			return (1);
		else if (ft_strnequ(line, COMMENT_CMD_STRING, 8) && set_comment(line, set)) // check si .comment est bon et pas autre chose (..comment ou .commenn)
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

int		name_comment_set(t_set *set)
{
	if (set->name == 1 && set->comment == 1)
		return (1);
	return (0);
}

int					check_header(int fd, char *line)
{
	t_set set;
	int		line_nb;
	//lecture des trois premiere lignes, Verification .name et .comment
	line_nb = 0;
	while (get_next_line(fd, &line) > 0 && !name_comment_set(&set)) // cette ft renvoit 1 si .name et .comment sont deja set
	{
		line = epur_str(line); // supprime les espaces en debut de ligne
		line_nb++;
		if (*line == COMMENT_CHAR) // si c'est un com, on l'ignore et on passe a la prochaine itération de GNL
			continue ;
		else if (line_is_point(line, &set)) // verifie si c'est .name ou .comment
			continue ;
		else
		{
			ft_putstr("Lexical error on line ");
			ft_putnbr_c(line_nb, '\n');
			return (0);
		}
	}
	return (1);
}
