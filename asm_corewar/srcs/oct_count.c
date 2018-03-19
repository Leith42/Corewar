/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:49:24 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/19 01:10:04 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		oct_prec(int pos, char **inst, int nb)
{
	int		i;
	int		type;

	i = nb;
	if (nb == 0)
		return (0);
	while (inst[i])
	{
		if (i > nb)
		{
			type = param_type(inst[i]);
			if (type == T_REG)
				pos -= 1;
			if (type == T_DIR)
				pos -= 4;
			if (type == T_IND)
				pos -= 2;
		}
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
