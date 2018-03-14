/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:53:40 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/14 22:18:24 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_sti(t_process *process, t_env *env)
{
	unsigned short	type[3];
	unsigned int	val[3];

	type[1] = get_param_type(env, process->pc, OP_STI, 1);
	type[2] = get_param_type(env, process->pc, OP_STI, 2);
	val[0] = get_param_raw_value(env, process->pc + 2, T_REG, OP_STI);
	val[1] = get_param_raw_value(env, process->pc + 3, type[1], OP_STI);
	if (!(get_param_type(env, process->pc, OP_STI, 0) == T_REG && type[1] &
		g_op_tab[OP_STI - 1].param_type[1] && type[2] &
		g_op_tab[OP_STI - 1].param_type[2] && val[0] > 0 && val[0] <= REG_NUMBER
		&& (type[1] != T_REG || (val[1] > 0 && val[1] <= REG_NUMBER))))
		return (0);
	val[0] = process->reg[val[0] - 1];
	val[2] = get_param_raw_value(env, process->pc + 3 +
			((type[1] == T_REG) ? 1 : 2), type[2], OP_STI);
	if (!(type[2] != T_REG || (val[2] > 0 && val[2] <= REG_NUMBER)))
		return (0);
	val[2] = (type[2] == T_REG) ? process->reg[val[2] - 1] : val[2];
	if (type[1] != T_DIR)
		val[1] = (type[1] == T_REG) ? process->reg[val[1] - 1]
			: get_uintfrom_char(env, (process->pc +
			(((short)(val[1])) % IDX_MOD)) % MEM_SIZE, 4);
	write_uint_to_char(env, (process->pc + (((short)(val[1] + val[2]))
		% IDX_MOD)) % MEM_SIZE, 4, val[0]);
	return (0);
}
