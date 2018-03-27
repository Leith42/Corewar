/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 01:10:03 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/22 10:11:56 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** AFF_LABEL - fonction utilitaire servant juste à afficher la totalité des \
labels (pour tests)
*/

void		aff_label(t_label *label_lst)
{
	t_label *tmp;

	tmp = label_lst;
	while (tmp)
	{
		ft_printf("label = %s, de type %d, et d'octet %d\n", tmp->name, tmp->type, tmp->oct);
		tmp = tmp->next;
	}
}

/*
** SET_LABEL_NAME - assigne le nom du label dans la structure
*/

void		set_label_name(t_label *new, char *src)
{
	if (src[0] == DIRECT_CHAR)
	{
		new->name = ft_strsub(src, 2, ft_strlen(src) - 2);
		new->type = 1;
	}
	else
		new->name = ft_strsub(src, 0, ft_strlen(src) - 1);
}

/*
** ADD_TO_LST - ajoute le maillon en fin de liste chainée
*/

t_label		*add_to_lst(t_label *label_list, t_label *new)
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

int			check_label_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR && str[i - 1] == DIRECT_CHAR)
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

t_label		*check_label(char **inst, t_label *label_list, int pos)
{
	int			i;
	char		*label_tmp;
	t_label		*new;

	i = 0;
	new = NULL;
	label_tmp = NULL;
	while (inst[i])
	{
		if (check_label_char(inst[i]))
		{
			if (!(new = ft_memalloc(sizeof(t_label))))
				return (NULL);
			set_label_name(new, inst[i]);
			if (new->type == 0)
				label_tmp = ft_strdup(new->name);
			if (label_tmp && new->type && !ft_strcmp(label_tmp, new->name))
			{
				new->oct = 0;
				new->is_set = 1;
			}
			else
				new->oct = pos;
			label_list = add_to_lst(label_list, new);
		}
		i++;
	}
	free(label_tmp);
	return (label_list);
}