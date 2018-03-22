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

void	replace_dist(t_label *label, t_lst_op *lst)
{
	int		i;

	i = 0;
	while (label)
	{
		if (label->type > 0)
		{
			while (lst && label->line > i)
			{
				lst = lst->next;
				i++;
			}
			lst->op[label->place] = label->res;
		}
		label = label->next;
	}
}

int		oct_prec(int pos, char **inst, int nb)
{
	int		i;
	int		type;

	i = nb;
	if (nb == 0)
		return (0);
	while (inst[i] && (type = param_type(inst[i])) != 0)
	{
		if (type == T_REG && i > nb)
			pos -= 1;
		if (type == T_DIR && i > nb)
			pos -= 4;
		if (type == T_IND && i > nb)
			pos -= 2;
		i++;
	}
	return (pos);
}

void	calc_dist_label(t_label *label, t_lst_op *lst)
{
	t_label	*dec;
	t_label	*app;

	dec = label;
	app = label;
	lst = NULL;
	while (app)
	{
		if (app->type > 0)
		{
			while (dec && (ft_strcmp(app->name, dec->name) || \
					dec->type > 0))
				dec = dec->next;
			if (ft_strcmp(app->name, dec->name) && dec->type > 0)
				app->res = (dec->oct + MEM_SIZE - app->oct) % MEM_SIZE;
		}
		app = app->next;
		dec = label;
	}
}

void	oct_count(char **inst, int pos, t_label *label)
{
	int			nb;
	t_label		*tmp;

	nb = 0;
	ft_putendl("lol");
	tmp = label;
	while (tmp->next && tmp->next->oct != -1)
		tmp = tmp->next;
	ft_putendl("lol2");
	while (inst[nb])
	{
		if (check_label_char(inst[nb]) == 1)
		{
			ft_putendl("lol3");
			tmp->oct = tmp->oct_tmp;
			//tmp->place = oct_prec(pos, inst, nb - 1);
			if (tmp != NULL)
				tmp = tmp->next;
		}
		nb++;
	}
	ft_putendl("lol4");
	tmp->oct_tmp += pos;
	ft_printf("pos_tmp = %d\n", tmp->oct_tmp);
}
