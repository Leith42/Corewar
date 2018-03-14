/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:23 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 00:01:23 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** T_DIR | T_IND, T_REG
*/

int	do_ld(t_process *process, t_env *env)
{
	unsigned short	param0_type;
	unsigned int	val[2];

	param0_type = get_param_type(env, process->pc, OP_LD, 0);
	if (!(get_param_type(env, process->pc, OP_LD, 1) == T_REG
		&& is_reg(val[1])
		&& param0_type & g_op_tab[OP_LD - 1].param_type[0]
		return (0);
	if (param0_type == T_DIR)
	{
		val[1] = get_param_raw_value(env, process->pc + 6, T_REG, OP_LD);
		val[0] = get_param_raw_value(env, process->pc + 2, param0_type, OP_LD);
	}
	else if (param0_type == T_IND)
	{
		val[1] = get_param_raw_value(env, process->pc + 4, T_REG, OP_LD);
		val[0] = get_uintfrom_char(env, (process->pc +
				(((short)(val[0])) % IDX_MOD)) % MEM_SIZE, 4);
	}
	process->reg[val[1] - 1] = val[0];
	process->carry = (val[0]) ? 0 : 1;
	return (0);
}
