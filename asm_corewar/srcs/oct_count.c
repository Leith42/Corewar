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
	int final_place = lst_node->label_pos[pos_tmp];

	i = 0;
	final_place++;
	while (i < 2)
	{
		lst_node->op[final_place] = res;
		final_place--;
		res >>= 8;
		i++;
	}
	i = 0;
	while (i < lst_node->pos)
		printf("%02x ,", lst_node->op[i++]);
	printf("\n");
}

/*
** Calcule et renvoi la valeur entre le call et sa déclaration
*/

int		set_to_call(t_label *tmp_label, t_lst_op *tmp_lst, char *to_search, int i)
{
	int res;

	res = tmp_lst->pos;
	printf("AU TOUT DEBUT ON est sur %02x avec un res de %d\n", tmp_lst->op[0], res);
	while (i < tmp_lst->label_nb)
	{
		i++;
		tmp_label = tmp_label->next;
	}
	tmp_lst = tmp_lst->next;
	printf("on rentre dans set_to_call et le pos_tmp = %d\n", res);
	while (tmp_lst)
	{
		i = 0;
		printf("maillon rentré est %02x\n", tmp_lst->op[0]);
		while (tmp_label->type == 0)
		{
			printf("on rentre dans la boucle du while et le label est %s\n", tmp_label->name);
			if (ft_strcmp(tmp_label->name, to_search) == 0)
			{
				printf("on sort avec une pos de %d\n", res);
				return (res);
			}
			if (tmp_lst->label_nb == 0)
			{
				res += tmp_lst->pos;
				tmp_lst = tmp_lst->next;
			}
			tmp_label = tmp_label->next;
		}
		while (i < tmp_lst->label_nb)
		{
			i++;
			printf("on outrepasse la label %s\n", tmp_label->name);
			tmp_label = tmp_label->next;
		}
		res += tmp_lst->pos;
		printf("on a outrepasse et le cumul de res est mtn de %d\n", res);
		tmp_lst = tmp_lst->next;
	}
	return (0);
}

/*
** Repart au début du fichier et cherche les appels 
** correspondants à la déclaration (to_search)
*/

void	ft_label(char *to_search, t_label *label, t_lst_op *lst)
{
	int i;
	int res;
	int before;
	t_label *tmp_label = label;
	t_lst_op *tmp_lst = lst;

	res = 0;
	before = 0;
	while (tmp_lst)
	{
		i = 0;
		while (tmp_label->type == 0)
		{
			if (ft_strcmp(tmp_label->name, to_search) == 0 && before == 0)
				before = 1;
			tmp_label = tmp_label->next;
		}
		while (i < tmp_lst->label_nb)
		{
			printf("on rentre ici une %de fois et le label est %s\n", i+1, tmp_label->name);
			if (!ft_strcmp(to_search, tmp_label->name) && tmp_label->is_set == 0)
			{
				printf("ca correspond !! avec %s\n", tmp_label->name);
				if (before == 0)
				{
					res = set_to_call(tmp_label, tmp_lst, to_search, i);
					printf("res apres calcul = %d\n", res);
					add_value_to_inst(res, tmp_lst, i);
					res = 0;
				}
				else
				{
					//return ;
					//add_value_to_inst(res, tmp_lst, i);
				}
			}
			i++;
			tmp_label = tmp_label->next;
		}
		res += tmp_lst->pos;
		tmp_lst = tmp_lst->next;
	}
}

/*
** Cherche un label (déclaration) 
*/

void	calc_dist_label(t_label *label, t_lst_op *lst)
{
	t_label *tmp_label;
	tmp_label = label;
	while (tmp_label)
	{
		if (tmp_label->type == 0)
		{
			printf("ok on cherche %s\n,", tmp_label->name);
			ft_label(tmp_label->name, label, lst);
			tmp_label->is_set = 1;
			printf("on est sorti avec %s géré!\n", tmp_label->name);
		}
		tmp_label = tmp_label->next;
	}
}