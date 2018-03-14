/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:53:40 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/14 20:53:28 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_sti(t_process *process, t_env *env)
{
	unsigned short	type_2;
	unsigned short	type_3;
	unsigned int	val_1;
	unsigned int	val_2;
	unsigned int	val_3;

	type_2 = get_param_type(env, process->pc, OP_STI, 1);
	type_3 = get_param_type(env, process->pc, OP_STI, 2);
	val_1 = get_param_raw_value(env, process->pc + 2, T_REG, OP_STI);
	val_2 = get_param_raw_value(env, process->pc + 3, type_2, OP_STI);
	if (get_param_type(env, process->pc, OP_STI, 0) == T_REG
		&& (type_2 & g_op_tab[OP_STI - 1].param_type[1]) != 0
		&& (type_3 & g_op_tab[OP_STI - 1].param_type[2]) != 0
		&& val_1 > 0 && val_1 <= REG_NUMBER
		&& (type_2 != T_REG || (val_2 > 0 && val_2 <= REG_NUMBER)))
	{
		val_1 = process->reg[val_1 - 1];
		val_3 = get_param_raw_value(env,
				process->pc + 3 + ((type_2 == T_REG) ? 1 : 2),
				type_3, OP_STI);
		if (type_3 != T_REG || (val_3 > 0 && val_3 <= REG_NUMBER))
		{
			val_3 = (type_3 == T_REG) ? process->reg[val_3 - 1] : val_3;
			if (type_2 != T_DIR)
				val_2 = (type_2 == T_REG) ? process->reg[val_2 - 1]
					: get_uintfrom_char(env,
					(process->pc + (((short)(val_2)) % IDX_MOD)) % MEM_SIZE, 4);
			write_uint_to_char(env,
				(process->pc + (((short)(val_2 + val_3)) % IDX_MOD)) % MEM_SIZE,
				4, val_1);
		}
	}
	skip_pc(env, process);
	return (0);
}
