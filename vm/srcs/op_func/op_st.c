/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:38 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 18:03:58 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_st(t_process *process, t_env *env)
{
	unsigned int	val_1;
	unsigned int	val_2;
	unsigned short	type_2;
	unsigned int	write_pc;

	val_1 = get_param_raw_value(env, process->pc + 1, T_REG, OP_ST);
	type_2 = get_param_type(env, process->pc, OP_ST, 1);
	val_2 = get_param_raw_value(env, process->pc + 2, type_2, OP_ST);
	if (!(get_param_type(env, process->pc, OP_ST, 0) != T_REG
		|| get_param_type(env, process->pc, 0x00, 2) != 0
		|| (type_2 != T_IND && type_2 != T_REG)
		|| !is_reg(val_1)
		|| (type_2 == T_REG && !is_reg(val_2))))
	{
		if (type_2 == T_REG)
			process->reg[val_2 - 1] = val_1;
		else
		{
			write_uint_to_char(env, write_pc = (process->pc + ((short)val_2) % IDX_MOD),
				REG_SIZE, val_1);
			env->mask[(write_pc + 0) % MEM_SIZE] = process->champ_id;
			env->mask[(write_pc + 1) % MEM_SIZE] = process->champ_id;
			env->mask[(write_pc + 2) % MEM_SIZE] = process->champ_id;
			env->mask[(write_pc + 3) % MEM_SIZE] = process->champ_id;
		}
	}
	return (0);
}
