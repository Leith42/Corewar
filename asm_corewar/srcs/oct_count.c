/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:49:24 by lgraham           #+#    #+#             */
/*   Updated: 2018/04/05 04:17:49 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			only_on_two(char op)
{
	if (op == 3 || op == 9 || op == 10 || op == 11 || op == 12 || op == 14 || op == 15)
		return (1);
	return (0);
}

void		set_by_type(int *dir_size, int *final_place, int type)
{
	if (type == 2)
	{
		*dir_size = 2;
		*final_place += 1;
	}
	else
	{
		*dir_size = 4;
		*final_place += 3;
	}
}

/*
** Ajoute la value au bon endroit dans la liste d'instructions
*/

static void	add_value_to_inst(int res, t_lst_op *lst_node, int pos_tmp, int type)
{
	int i;
	int final_place;
	int dir_size;

	i = 0;
	final_place = lst_node->label_pos[pos_tmp];
	if (lst_node->op[0] == 1)
	{
		dir_size = 4;
		final_place += 3;
	}
	else if (only_on_two(lst_node->op[0]))
	{
		dir_size = 2;
		final_place++;
	}
	else
		set_by_type(&dir_size, &final_place, type);
	while (i < dir_size)
	{
		lst_node->op[final_place] = (unsigned char)res;
		final_place--;
		res >>= 8;
		i++;
	}
}

/*
** Calcule et renvoi la valeur entre le call et sa déclaration
*/

static int	calculate_res(t_lst_op *tmp_lst, t_label *tmp_label, int line)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < line)
	{
		res += tmp_lst->pos;
		tmp_lst = tmp_lst->next;
		i++;
	}
	tmp_label->is_set = 1;
	return (res);
}

/*
**	Parcours tous les labels qui sont APRÈS la déclaration
**	et y ajoute la valeur négative
*/

static void	search_label_call_after(char *to_search,
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

static void	search_label_call(char *to_search, t_label *label,
			t_lst_op *lst, int line)
{
	int			i;
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
		i = 0;
		while (i < lst->label_nb)
		{
			if (ft_strequ(to_search, label->name) && !label->is_set)
			{
				add_value_to_inst(calculate_res(lst, label,
							line - line_diff), lst, i, label->type);
				label->is_set = 1;
			}
			i++;
			label = label->next;
		}
		lst = lst->next;
		if (lst && !label)// a corriger ? maillon en trop dans la chaine
			return ;
	}
}

/*
** Check si un label appellé trouve bien son parent
*/

static char	*check_label_match(t_label *label)
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

int			fill_label(t_label *label, t_lst_op *lst)
{
	int		nbw;
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
		printf("No such label reference > %s < found in the file\n",
				label_error);
		return (0);
	}
	// Affichage >>
	while (lst)
	{
		nbw = 0;
		while (nbw < lst->pos)
			printf("%02x ", lst->op[nbw++]);
		printf("\n");
		lst = lst->next;
	}
	// << temporaire
	free_label(label);
	return (1);
}
