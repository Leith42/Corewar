/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_label_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:49:24 by lgraham           #+#    #+#             */
/*   Updated: 2018/04/09 23:20:19 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Parcours tous les labels qui sont APRÈS la déclaration
**	et y ajoute la valeur négative
*/

static void		search_label_call_after(char *to_search,
			t_label *tmp_label, t_lst_op *tmp_lst)
{
	int res;
	int i;

	res = 0;
	while (tmp_label && (tmp_label->type == 0 || tmp_label->type == -1))
		tmp_label = tmp_label->next;
	while (tmp_lst)
	{
		while (tmp_label && (tmp_label->type == 0 || tmp_label->type == -1))
			tmp_label = tmp_label->next;
		i = 0;
		while (i < tmp_lst->label_nb)
		{
			if (ft_strcmp(tmp_label->name, to_search) == 0)
			{
				add_value_to_inst(0 - res, tmp_lst, i, tmp_label->type);
				tmp_label->is_set = 1;
			}
			tmp_label = tmp_label->next;
			i++;
		}
		res += tmp_lst->pos;
		tmp_lst = tmp_lst->next;
	}
}

/*
** Repart au début du fichier et cherche les appels
** correspondants à la déclaration (to_search) FONCTION A NORMER
*/

static t_label	*search_label_call_bis(t_lst_op *lst, char *to_search,
			t_label *label, int line_minus_line_diff)
{
	int		i;

	i = 0;
	while (i < lst->label_nb)
	{
		if (ft_strequ(to_search, label->name) && !label->is_set)
		{
			add_value_to_inst(calculate_res(lst, label,
				line_minus_line_diff), lst, i, label->type);
			label->is_set = 1;
		}
		i++;
		label = label->next;
	}
	return (label);
}

static void		search_label_call(char *to_search, t_label *label,
			t_lst_op *lst, int line)
{
	int			line_diff;

	line_diff = 0;
	while (lst)
	{
		line_diff++;
		while (label->type == 0 || label->type == -1)
		{
			if (ft_strequ(label->name, to_search))
			{
				while (line_diff < line)
				{
					lst = lst->next;
					line_diff++;
				}
				search_label_call_after(to_search, label, lst);
				return ;
			}
			label = label->next;
		}
		label = search_label_call_bis(lst, to_search, label, line - line_diff);
		lst = lst->next;
		if (lst && !label)// a corriger ? maillon en trop dans la chaine
			return ;
	}
}

/*
** Check si un label appellé trouve bien son parent
*/

static char		*check_label_match(t_label *label)
{
	while (label)
	{
		if (label->type == 1 && label->is_set == 0)
			return (label->name);
		label = label->next;
	}
	return (NULL);
}

/*
** Cherche un label déclaré
*/

int				fill_label(t_label *label, t_lst_op *lst)
{
	char	*label_error;
	t_label	*tmp_label;

	tmp_label = label;
	while (tmp_label)
	{
		if (tmp_label->type == 0 || tmp_label->type == -1)
			search_label_call(tmp_label->name, label, lst, tmp_label->line);
		tmp_label = tmp_label->next;
	}
	if ((label_error = check_label_match(label)))
	{
		printf("No such label reference \"%s\" found in the file\n",
		label_error);
		return (0);
	}
	free_label(label);
	return (1);
}
