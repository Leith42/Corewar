/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:52:13 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/12 22:11:17 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_or(t_process *process, t_env *env)
{
	unsigned short	param_type[3];
	unsigned int	param_value[3];
	unsigned int	skip;

	param_type[0] = get_param_type(env, process->pc, OP_OR, 0);
	param_type[1] = get_param_type(env, process->pc, OP_OR, 1);
	param_type[2] = get_param_type(env, process->pc, OP_OR, 2);
	if (param_type[2] == T_REG)
	{
		param_value[0] = get_param_raw_value(
				env, process->pc + 2, param_type[0], OP_OR);
		skip = (param_type[0] == T_DIR || param_type[0] == T_IND) ? 5 : 3;
		param_value[1] = get_param_raw_value(
				env, process->pc + skip, param_type[1], OP_OR);
		skip += (param_type[1] == T_DIR || param_type[1] == T_IND) ? 4 : 2;
		param_value[2] = get_param_raw_value(
				env, process->pc + skip, param_type[2], OP_OR);
		if (is_reg(param_value[2]))
		{
			process->reg[param_value[2] - 1] = param_value[0] | param_value[1];
			return (process->reg[param_value[2] - 1]);
		}
	}
	return (0);
}
