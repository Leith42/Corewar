/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 01:10:03 by lgraham           #+#    #+#             */
/*   Updated: 2018/04/05 04:28:23 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** SET_LABEL_NAME - assigne le nom du label dans la structure
*/

static void		set_label_name(t_label *new, char *src,
				char *src_next, int line)
{
	if (src[0] == DIRECT_CHAR)
	{
		new->name = ft_strsub(src, 2, ft_strlen(src) - 2);
		new->type = 1;
	}
	else if (src[0] == LABEL_CHAR)
	{
		new->name = ft_strsub(src, 1, ft_strlen(src) - 1);
		new->type = 2;
	}
	else
	{
		new->name = ft_strsub(src, 0, ft_strlen(src) - 1);
		new->line = line;
		if (src_next == NULL)
		{
			new->type = -1;
			new->line = line + 1;
		}
	}
}

/*
** ADD_TO_LST - ajoute le maillon en fin de liste chainée
*/

static t_label	*add_to_lst(t_label *label_list, t_label *new)
{
	t_label *tmp;

	tmp = label_list;
	if (!label_list)
		label_list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (label_list);
}

/*
** CHECK_LABEL_CHAR - Check si l'argument reçu est un label
*/

int				check_label_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR && i > 0 && str[i - 1] == DIRECT_CHAR)
			return (1);
		else if (i > 0 && str[0] == LABEL_CHAR)
			return (1);
		i++;
	}
	if (i >= 2 && str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}

/*
** CHECK_LABEL - Créer ou MAJ une liste chainée t_label et la renvoit
*/

t_label			*set_label(char **inst, t_label *label_list, int pos, int line)
{
	int			i;
	char		*label_tmp;
	t_label		*new;

	i = 0;
	new = NULL;
	label_tmp = NULL;
	while (inst[i])
	{
	//	printf("inst = >%s<\n", inst[i]);
		if (check_label_char(inst[i]))
		{
			if (!(new = ft_memalloc(sizeof(t_label))))
				return (NULL);
			set_label_name(new, inst[i], inst[i + 1], line);
			label_tmp = (new->type == 0) ? ft_strdup(new->name) : label_tmp;
			new->oct = (label_tmp && new->type == 1 && !ft_strcmp(\
				label_tmp, new->name)) ? 0 : pos;
			if (label_tmp && new->type == 1 && !ft_strcmp(label_tmp, new->name))
				new->is_set = 1;
			label_list = add_to_lst(label_list, new);
		}
		i++;
	}
	return (label_list);
}

/*
**	fill_label_pos - Remplit le tableau de pos et assigne
**	la derniere pos connue en fin de tableau
*/

void			fill_label_pos(int *tab, int pos)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = pos;
}
