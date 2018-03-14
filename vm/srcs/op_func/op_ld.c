/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:23 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 00:13:44 by mgonon           ###   ########.fr       */
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
	val[1] = get_param_raw_value(env, process->pc + (
		(param0_type == T_DIR) ? 2 + 4 : 2 + 2), T_REG, OP_LD);
	if (!(get_param_type(env, process->pc, OP_LD, 1) == T_REG
		&& is_reg(val[1])
		&& param0_type & g_op_tab[OP_LD - 1].param_type[0]))
		return (0);
	val[0] = get_param_raw_value(env, process->pc + 2, param0_type, OP_LD);
	if (param0_type == T_IND)
		val[0] = get_uintfrom_char(env, (process->pc +
				(((short)(val[0])) % IDX_MOD)) % MEM_SIZE, 4);
	process->reg[val[1] - 1] = val[0];
	return ((val[0] == 0) ? 0 : 1);
}
