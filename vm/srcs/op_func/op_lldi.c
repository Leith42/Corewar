/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:54:26 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 17:34:25 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_lldi(t_process *process, t_env *env)
{
	unsigned short	type[3];
	unsigned int	val[3];

	type[0] = get_param_type(env, process->pc, OP_LDI, 0);
	type[1] = get_param_type(env, process->pc, OP_LDI, 1);
	val[0] = get_param_raw_value(env, process->pc + 2, type[0], OP_LDI);
	val[1] = get_param_raw_value(env,
			process->pc + 2 + ((type[0] == T_REG) ? 1 : 2), type[1], OP_LDI);
	val[2] = get_param_raw_value(env,
			process->pc + 2 + ((type[0] == T_REG) ? 1 : 2) +
			((type[1] == T_REG) ? 1 : 2), type[1], OP_LDI);
	if (!(get_param_type(env, process->pc, OP_LDI, 2) == T_REG && type[0] &
		g_op_tab[OP_LDI - 1].param_type[0] && type[1] &
		g_op_tab[OP_LDI - 1].param_type[1] && is_reg(val[2])
		&& (type[0] != T_REG || is_reg(val[0]))))
		return (0);
	val[1] = (type[1] == T_REG) ? process->reg[val[1] - 1] : val[1];
	if (type[0] != T_DIR)
		val[0] = (type[0] == T_REG) ? process->reg[val[0] - 1]
			: get_uintfrom_char(env, (process->pc +
			(((short)(val[0])) % IDX_MOD)) % MEM_SIZE, 4);
	process->reg[val[2] - 1] = get_uintfrom_char(env,
			(process->pc + val[0] + val[1]) % MEM_SIZE, 4);
	return (0);
}
