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
			ft_putstr("Hello\n");
			while (dec && (ft_strcmp(app->name, dec->name) != 0 || \
					dec->type > 0))
				dec = dec->next;
			if (!ft_strcmp(app->name, dec->name))
			{
				app->res = (dec->oct + 65531 - app->oct) % MEM_SIZE;
				ft_printf("app->res1 = %d\n", app->res);
			}
		}
	/*	ft_printf("app->name = %s\n", app->name);
		ft_printf("dec->name = %s\n", dec->name);
		ft_printf("app->res = %d\n", app->res);
		ft_printf("app->oct = %d\n", app->oct);
		ft_printf("dec->oct = %d\n", dec->oct);
	*/	ft_putchar('\n');
		app = app->next;
		dec = label;
	}
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
