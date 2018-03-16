/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:38 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/16 20:33:23 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_st(t_process *process, t_env *env)
{
	unsigned int	val[2];
	unsigned short	type_2;
	unsigned int	write_pc;

	val[0] = get_param_raw_value(env, process->pc + 2, T_REG, OP_ST);
	type_2 = get_param_type(env, process->pc, OP_ST, 1);
	val[1] = get_param_raw_value(env, process->pc + 3, type_2, OP_ST);
	if (get_param_type(env, process->pc, OP_ST, 0) != T_REG
		|| get_param_type(env, process->pc, 0x00, 2) != 0
		|| (type_2 != T_IND && type_2 != T_REG)
		|| !is_reg(val[0])
		|| (type_2 == T_REG && !is_reg(val[1])))
		return (0);
	if (type_2 == T_REG)
		process->reg[val[1] - 1] = val[0];
	else
	{
		write_uint_to_char(env, write_pc = (process->pc +
				((short)val[1]) % IDX_MOD), REG_SIZE, val[0]);
		env->mask[(write_pc + 0) % MEM_SIZE] = process->champ_id;
		env->mask[(write_pc + 1) % MEM_SIZE] = process->champ_id;
		env->mask[(write_pc + 2) % MEM_SIZE] = process->champ_id;
		env->mask[(write_pc + 3) % MEM_SIZE] = process->champ_id;
	}
	return (0);
}
