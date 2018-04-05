/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:51:00 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/27 18:55:04 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_add(t_process *process, t_env *env)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	tmp;
	unsigned int	res;

	tmp = 0;
	while (tmp < 3 && get_param_type(env, process->pc, OP_ADD, tmp) == T_REG)
		tmp++;
	a = get_param_raw_value(env, process->pc + 2, T_REG, OP_ADD);
	b = get_param_raw_value(env, process->pc + 3, T_REG, OP_ADD);
	c = get_param_raw_value(env, process->pc + 4, T_REG, OP_ADD);
	if (!(tmp < 3 || !is_reg(a) || !is_reg(b) || !is_reg(c)))
	{
		res = process->reg[a - 1] + process->reg[b - 1];
		process->reg[c - 1] = res;
	}
	else
		res = 1;
	return ((int)res);
}
