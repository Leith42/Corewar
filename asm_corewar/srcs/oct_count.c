/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:49:24 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/19 02:25:18 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** label->oct_tmp sauve la valeur totale courante d'octet depuis le debut du fichier
** dans la fonction add_to_lst() du check_label.c jusqu'au debut de la ligne lue par
** gnl.
** label->oct sauve la valeur octale finale de la position du label.
*/

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

void	oct_count(char **inst, int pos, t_label *label)
{
	int			nb;
	t_label		*tmp;

	nb = 0;
	tmp = label;
	while (tmp->next && tmp->next->oct != -1)
		tmp = tmp->next;
	while (inst[nb])
	{
		if (check_label_char(inst[nb]) == 1)
		{
			tmp->oct = tmp->oct_tmp + oct_prec(pos, inst, nb); 
			tmp = tmp->next;
		}
		nb++;
	}
	tmp->oct_tmp += pos;
}
