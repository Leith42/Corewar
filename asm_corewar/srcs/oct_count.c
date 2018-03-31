/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:49:24 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/22 10:11:54 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Ajoute la value au bon endroit dans la liste d'instructions
*/

void	add_value_to_inst(int res, t_lst_op *lst_node, int pos_tmp)
{
	int i;
	int final_place;
	int dir_size;

	i = 0;
	dir_size = (g_op_tab[lst_node->op[0] - 1].addr_or_nb == 1) ? 2 : 4;
	final_place = lst_node->label_pos[pos_tmp];
	if (dir_size == 2)
		final_place++;
	else
		final_place += 3;
	while (i < dir_size)
	{
		lst_node->op[final_place] = res;
		final_place--;
		res >>= 8;
		i++;
	}
}

/*
** Calcule et renvoi la valeur entre le call et sa déclaration
*/

int		calculate_res(t_lst_op *tmp_lst, t_label *tmp_label, int line)
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
** Parcours tous les labels qui sont APRÈS la déclaration et y ajoute la valeur négative
*/

void	search_label_call_after(char *to_search, t_label *tmp_label, t_lst_op *tmp_lst)
{
	int res;
	int i;

	res = 0;
	while (tmp_label && (tmp_label->type == 0 || tmp_label->type == -1))
		tmp_label = tmp_label->next;
	while (tmp_lst)
	{
		i = 0;
		while (tmp_label && (tmp_label->type == 0 || tmp_label->type == -1))
			tmp_label = tmp_label->next;
		while (i < tmp_lst->label_nb)
		{
			if (ft_strcmp(tmp_label->name, to_search) == 0)
				add_value_to_inst(0 - res, tmp_lst, i);
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

void	search_label_call(char *to_search, t_label *label, t_lst_op *lst, int line)
{
	int			i;
	int			res;
	int			before;
	int			line_diff;
	t_label		*tmp_label;
	t_lst_op	*tmp_lst;

	res = 0;
	line_diff = 0;
	tmp_label = label;
	tmp_lst = lst;
	before = 0;
	while (tmp_lst)
	{
		i = 0;
		line_diff++;
		while (tmp_label->type == 0 || tmp_label->type == -1)
		{
			if (ft_strcmp(tmp_label->name, to_search) == 0)
			{
				while (line_diff < line)
				{
					tmp_lst = tmp_lst->next;
					line_diff++;
				}
				search_label_call_after(to_search, tmp_label, tmp_lst);
				return ;
			}
			tmp_label = tmp_label->next;
		}
		while (i < tmp_lst->label_nb)
		{
			if (!ft_strcmp(to_search, tmp_label->name) && tmp_label->is_set == 0)
			{
				res = calculate_res(tmp_lst, tmp_label, line - line_diff);
				add_value_to_inst(res, tmp_lst, i);
			}
			i++;
			tmp_label = tmp_label->next;
		}
		tmp_lst = tmp_lst->next;
		if (tmp_lst && !tmp_label)// a corriger ? maillon en trop dans la chaine
			return ;
	}
}

/*
** Cherche un label déclaré
*/

void	fill_label(t_label *label, t_lst_op *lst)
{
	int		nbw;
	t_label	*tmp_label;

	tmp_label = label;
	nbw = 0;
	while (tmp_label)
	{
		if (tmp_label->type == 0 || tmp_label->type == -1)
			search_label_call(tmp_label->name, label, lst, tmp_label->line);
		tmp_label = tmp_label->next;
	}
	while (lst)
	{
		nbw = 0;
		while (nbw < lst->pos)
			printf("%02x ", lst->op[nbw++]);
		printf("\n");
		lst = lst->next;
	}
}
