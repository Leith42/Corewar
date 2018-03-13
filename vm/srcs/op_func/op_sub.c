/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:51:30 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/13 23:39:22 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_sub(t_process *process, t_env *env)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	tmp;
	unsigned int	res;

	tmp = 0;
	while (tmp < 3 && get_param_type(env, process->pc, 0x04, tmp) == T_REG)
		tmp++;
	res = 0;
	if (tmp == 3)
	{
		a = get_param_raw_value(env, process->pc + 2, T_REG, 0x04);
		b = get_param_raw_value(env, process->pc + 3, T_REG, 0x04);
		c = get_param_raw_value(env, process->pc + 4, T_REG, 0x04);
		if (a < 1 || a > 16 || b < 1 || b > 16 || c < 1 || c > 16)
			return (-1);
		res = process->reg[a] - process->reg[b];
		process->reg[c] = res;
	}
	process->pc += 1 + 1 + 1 + 1;
	return ((int)res);
}
