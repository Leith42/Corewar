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
** label->oct_tmp sauve la valeur totale courante d'octet depuis le debut du fichier
** dans la fonction add_to_lst() du check_label.c jusqu'au debut de la ligne lue par
** gnl.
** label->oct sauve la valeur octale finale de la position du label.
*/
/*
void	replace_dist(t_label *label, t_lst_op *lst)
{
	int			i;
	t_lst_op	*tmp;

	i = 1;
	tmp = lst;
	while (label)
	{
		if (label->type > 0)
		{
			while (tmp && i < label->line)
			{
				tmp = tmp->next;
				i++;
			}
			ft_printf("name = %s\n", label->name);
			ft_printf("res = %d\n", label->res);
			ft_printf("place = %d\n", label->place);
			tmp = rmp_param(label->res, tmp, 2, label->place - 1);
		//	tmp->op[label->place - 1] = label->res;
		}
		label = label->next;
		tmp = lst;
		i = 1;
	}
}

int		oct_prec(int pos, char **inst, int nb)
{
	int		i;
	int		type;

	i = nb;
//	ft_printf("initial pos %d\n", pos);
	pos--;
	if (nb == 0)
		return (0);
	while (inst[i] && (type = param_type(inst[i])) != 0)
	{
		if (type == T_REG && i > nb)
			pos -= 1;
		if (type == T_DIR && i > nb)
			pos -= 2;
		if (type == T_IND && i > nb)
			pos -= 4;
		i++;
	}
//	ft_printf("final pos %d\n", pos);
	return (pos);
}

void	oct_count(char **inst, int pos, t_label *label)
{
	int			nb;
	t_label		*tmp;

	nb = 0;
	tmp = label;
	while (tmp->next && tmp->oct != -1)
		tmp = tmp->next;
	while (inst[nb])
	{
		if (check_label_char(inst[nb]) == 1)
		{
			tmp->oct = tmp->oct_tmp;
			tmp->place = oct_prec(pos, inst, nb);
			if (tmp->next != NULL)
				tmp = tmp->next;
		}
		nb++;
	}
	tmp->oct_tmp += pos;
}
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
	/*while (tmp_lst)
	{
		i = 0;
		while ((!to_search && tmp_label->type == 0) || (to_search && tmp_label->type == 0 && ft_strcmp(to_search, tmp_label->name)))
			{
			//	printf("on outrepasse le call %s\n", tmp_label->name);
				tmp_label = tmp_label->next;
			}
		while (i < tmp_lst->label_nb)
		{
		//	printf("le label traversé est %s et est de type %d\n", tmp_label->name, tmp_label->type);
			if (to_search && tmp_label->type == 0 && !ft_strcmp(to_search, tmp_label->name))
			{
				printf("on cherchait le label %s et il correspond avec le %s\n", to_search, tmp_label->name);
				add_value_to_inst(res, tmp_to_keep, pos_tmp);
				is_set_to_keep->is_set++;
				to_search = NULL;
				pos_tmp = 0;
				reset = 1;
				break ;
			}
			if (!to_search && tmp_label->type == 1 && tmp_label->is_set == 0)
			{
				printf("i = %d\n", i);
				to_search = ft_strdup(tmp_label->name);
				printf("on rentre la et ce quon cherche desormais est %s\n", to_search);
				is_set_to_keep = tmp_label;
				tmp_to_keep = tmp_lst;
				pos_tmp = i;
				printf("pos_tmp = %d\n", pos_tmp);
			//	printf("pos_tmp = %d\n", pos_tmp);
			}
			i++;
			tmp_label = tmp_label->next;
		}
		if (reset)
		{
			tmp_lst = tmp_to_keep;
			tmp_label = is_set_to_keep;
			is_set_to_keep = NULL;
			tmp_to_keep = NULL;
			reset = 0;
		}
		else if (to_search)
		{
			res += tmp_lst->pos;
			while (print < tmp_lst->pos)
				printf("%02x ,", tmp_lst->op[print++]);
			printf("\n");
			print = 0;
			printf("on prend cette ligne %s et res = %d\n", to_search, res);
			tmp_lst = tmp_lst->next;
		}
		else
		{
			printf("on cherche rien pour l'instant\n");
			res = 0;
			tmp_lst = tmp_lst->next;
		}
	}
}*/