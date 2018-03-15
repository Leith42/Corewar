/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:52:29 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 20:08:10 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_xor(t_process *process, t_env *env)
{
	unsigned short	param_type[3];
	unsigned int	param_value[3];
	unsigned int	skip;

	param_type[0] = get_param_type(env, process->pc, OP_XOR, 0);
	param_type[1] = get_param_type(env, process->pc, OP_XOR, 1);
	param_type[2] = get_param_type(env, process->pc, OP_XOR, 2);
	if (param_type[2] == T_REG)
	{
		param_value[0] = get_param_raw_value(
				env, process->pc + 2, param_type[0], OP_XOR);
		skip = (param_type[0] == T_DIR || param_type[0] == T_IND) ? 5 : 3;
		param_value[1] = get_param_raw_value(
				env, process->pc + skip, param_type[1], OP_XOR);
		skip += (param_type[1] == T_DIR || param_type[1] == T_IND) ? 4 : 2;
		param_value[2] = get_param_raw_value(
				env, process->pc + skip, param_type[2], OP_XOR);
		if (is_reg(param_value[2]))
		{
			process->reg[param_value[2] - 1] = param_value[0] ^ param_value[1];
			return ((process->reg[param_value[2] - 1] == 0) ? 0 : 1);
		}
	}
	return (0);
}
