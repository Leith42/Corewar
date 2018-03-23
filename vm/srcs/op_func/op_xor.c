/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:52:29 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/23 21:32:39 by gudemare         ###   ########.fr       */
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

static unsigned int	get_value(unsigned short param_type, unsigned int skip,
					t_process *process, t_env *env)
{
	unsigned int value;

	value = get_param_raw_value(env, process->pc + skip, param_type, OP_XOR);
	if (param_type == T_REG && is_reg(value))
		return (process->reg[value - 1]);
	else if (param_type == T_DIR)
		return (value);
	else if (param_type == T_IND)
		return (get_uintfrom_char(env, (process->pc +
			(((short)(value)) % IDX_MOD)) % MEM_SIZE, 4));
	else
		return (0);
}

int					do_xor(t_process *process, t_env *env)
{
	unsigned int	skip;
	unsigned short	param_type[3];
	unsigned int	param_value[3];

	skip = 2;
	param_type[0] = get_param_type(env, process->pc, OP_XOR, 0);
	param_type[1] = get_param_type(env, process->pc, OP_XOR, 1);
	param_type[2] = get_param_type(env, process->pc, OP_XOR, 2);
	if (!(param_type[0] != 0 && param_type[1] != 0 && param_type[2] == T_REG))
		return (0);
	param_value[0] = get_value(param_type[0], skip, process, env);
	skip += get_skip(param_type[0]);
	param_value[1] = get_value(param_type[1], skip, process, env);
	skip += get_skip(param_type[1]);
	param_value[2] = get_param_raw_value(
			env, process->pc + skip, param_type[2], OP_XOR);
	if (!(is_reg(param_value[2])
		&& (param_type[0] != T_REG || is_reg(param_value[0]))
		&& (param_type[1] != T_REG || is_reg(param_value[1]))))
		return (0);
	process->reg[param_value[2] - 1] =
		(param_value[0] ^ param_value[1]);
	return ((process->reg[param_value[2] - 1] == 0) ? 0 : 1);
}
