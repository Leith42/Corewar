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

int		set_to_call(t_label *tmp_label, t_lst_op *tmp_lst, int line, int i)
{
	int res;
	int nb;

	res = tmp_lst->pos;
	nb = 0;
	printf("AU TOUT DEBUT ON est sur %02x avec un res de %d\n sur un pos de %d\n", tmp_lst->op[0], res, tmp_lst->pos);
	while (i < tmp_lst->label_nb)
	{
		i++;
		tmp_label = tmp_label->next;
	}
	tmp_lst = tmp_lst->next;
//	printf("line recu dans set_to_call est %d\n", line);
//	printf("on rentre dans set_to_call et le pos_tmp = %d et le label oú on se trouve est %s et type %d\n", res, tmp_label->name, tmp_label->type);
	i = 0;
	while (i < line - 1)
	{
		nb = 0;
		printf("maillon rentré est %02x\n", tmp_lst->op[0]);
		while (tmp_label->type == -1 || tmp_label->type == 0)
			tmp_label = tmp_label->next;
		while (nb < tmp_lst->label_nb)
		{
			nb++;
			printf("on outrepasse la label %s\n", tmp_label->name);
			tmp_label = tmp_label->next;
		}
		res += tmp_lst->pos;
		printf("res dans la boucle de line = %d sur un pos de %d\n", res, tmp_lst->pos);
		tmp_lst = tmp_lst->next;
		i++;
	}
	return (res);
}

void	ft_after(char *to_search, t_label *tmp_label, t_lst_op *tmp_lst)
{
	int res;
	int i;

	res = 0;
	while (tmp_label->type == 0 || tmp_label->type == -1)
		tmp_label = tmp_label->next;
	printf(" on est pret est paré dans le after avec > %02x < et label %s de type %d\n", tmp_lst->op[0], tmp_label->name, tmp_label->type);
	while (tmp_lst)
	{
		i = 0;
		res += tmp_lst->pos;
		printf("res = %d, pos = %d, cumul de res est de %d\n", tmp_lst->pos - res, tmp_lst->pos, res);
		while (tmp_label && (tmp_label->type == 0 || tmp_label->type == -1))
			tmp_label = tmp_label->next;
		if (tmp_label)
			printf("label de type %d est celui la > %s\n", tmp_label->type, tmp_label->name);
		while (i < tmp_lst->label_nb)
		{
			if (ft_strcmp(tmp_label->name, to_search) == 0)
			{
				printf("ca correspond (after) !!\n");
				add_value_to_inst(65536 - res, tmp_lst, i);
			}
			i++;
			tmp_label = tmp_label->next;
		}
		tmp_lst = tmp_lst->next;
	}
}

/*
** Repart au début du fichier et cherche les appels 
** correspondants à la déclaration (to_search)
*/

void	ft_label(char *to_search, t_label *label, t_lst_op *lst, int line)
{
	int i;
	int res;
	int before;
	int	line_diff = 0;
	t_label *tmp_label = label;
	t_lst_op *tmp_lst = lst;

	res = 0;
	before = 0;
	while (tmp_lst)
	{
		i = 0;
		line_diff++;
		res += tmp_lst->pos;
		while (tmp_label->type == 0 || tmp_label->type == -1)
		{
			if (ft_strcmp(tmp_label->name, to_search) == 0)
			{
				printf("on sort de before et on change de FT\n");
				while (line_diff < line)
				{
					
					tmp_lst = tmp_lst->next;
					line_diff++;
				}
				ft_after(to_search, tmp_label, tmp_lst->next);
				return ;
			}
			tmp_label = tmp_label->next;
		}
		while (i < tmp_lst->label_nb)
		{
			
			printf("AU TOUT DEBUT ON est sur %02x avec un res de %d\n", tmp_lst->op[0], res);
			printf("on rentre ici une %de fois et le label est %s\n", i+1, tmp_label->name);
			if (!ft_strcmp(to_search, tmp_label->name) && tmp_label->is_set == 0)
			{
				printf("ca correspond !! avec %s\n", tmp_label->name);
				res = set_to_call(tmp_label, tmp_lst, line - line_diff, i);
				printf("res BEFORe = %d\n", res);
				add_value_to_inst(res, tmp_lst, i);
			}
			i++;
			tmp_label = tmp_label->next;
		}
		tmp_lst = tmp_lst->next;
		if (tmp_lst && !tmp_label) // a corriger ? maillon en trop dans la chaine
			return ;
	}
	
}

/*
** Cherche un label (déclaration) 
*/

void	calc_dist_label(t_label *label, t_lst_op *lst)
{
	t_label *tmp_label;
	tmp_label = label;
	int nbw = 0;
	while (tmp_label)
	{
		if (tmp_label->type == 0 || tmp_label->type == -1)
		{
			printf("ok on cherche %s<<<<<<<<<<<<<<< line = %d\n,", tmp_label->name, tmp_label->line);
			ft_label(tmp_label->name, label, lst, tmp_label->line);
			tmp_label->is_set = 1;
			printf("on est sorti avec %s géré!\n", tmp_label->name);
		}
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