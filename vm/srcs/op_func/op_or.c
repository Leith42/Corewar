/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:52:13 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/27 11:27:43 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	get_skip(unsigned short param_type)
{
	if (param_type == T_REG)
		return (1);
	else if (param_type == T_IND)
		return (2);
	else if (param_type == T_DIR)
		return (4);
	return (0);
}

static unsigned int	get_value(unsigned short param_type, unsigned int value,
					t_process *process, t_env *env)
{
	if (param_type == T_REG)
		return (process->reg[value - 1]);
	else if (param_type == T_DIR)
		return (value);
	else if (param_type == T_IND)
		return (get_uintfrom_char(env, (process->pc +
			(((short)(value)) % IDX_MOD)) % MEM_SIZE, 4));
	else
		return (0);
}

int					do_or(t_process *process, t_env *env)
{
	unsigned int	skip;
	unsigned short	param_type[3];
	unsigned int	param_value[3];

	skip = 2;
	param_type[0] = get_param_type(env, process->pc, OP_OR, 0);
	param_type[1] = get_param_type(env, process->pc, OP_OR, 1);
	param_type[2] = get_param_type(env, process->pc, OP_OR, 2);
	if (!(param_type[0] != 0 && param_type[1] != 0 && param_type[2] == T_REG))
		return (0);
	param_value[0] = get_param_raw_value(env, process->pc + skip,
			param_type[0], OP_OR);
	skip += get_skip(param_type[0]);
	param_value[1] = get_param_raw_value(env, process->pc + skip,
			param_type[1], OP_OR);
	skip += get_skip(param_type[1]);
	param_value[2] = get_param_raw_value(
			env, process->pc + skip, param_type[2], OP_OR);
	if (!(is_reg(param_value[2])
		&& (param_type[0] != T_REG || is_reg(param_value[0]))
		&& (param_type[1] != T_REG || is_reg(param_value[1]))))
		return (0);
	param_value[0] = get_value(param_type[0], param_value[0], process, env);
	param_value[1] = get_value(param_type[1], param_value[1], process, env);
	process->reg[param_value[2] - 1] =
		(param_value[0] | param_value[1]);
	return ((process->reg[param_value[2] - 1] == 0) ? 0 : 1);
}
