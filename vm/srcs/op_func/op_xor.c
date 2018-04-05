/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:52:29 by gudemare          #+#    #+#             */
/*   Updated: 2018/04/05 01:59:25 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	get_skip(unsigned short type)
{
	if (type == T_REG)
		return (1);
	else if (type == T_IND)
		return (2);
	else if (type == T_DIR)
		return (4);
	return (0);
}

static unsigned int	get_value(unsigned short type, unsigned int value,
					t_process *process, t_env *env)
{
	if (type == T_REG)
		return (process->reg[value - 1]);
	else if (type == T_DIR)
		return (value);
	else if (type == T_IND)
		return (get_uintfrom_char(env, (process->pc +
			(((short)(value)) % IDX_MOD)) % MEM_SIZE, 4));
	else
		return (0);
}

int					do_xor(t_process *process, t_env *env)
{
	unsigned int	skip;
	unsigned short	type[3];
	unsigned int	value[3];

	skip = 2;
	type[0] = get_param_type(env, process->pc, OP_XOR, 0);
	type[1] = get_param_type(env, process->pc, OP_XOR, 1);
	type[2] = get_param_type(env, process->pc, OP_XOR, 2);
	if (!(type[0] != 0 && type[1] != 0 && type[2] == T_REG))
		return (1);
	value[0] = get_param_raw_value(env, process->pc + skip, type[0], OP_XOR);
	skip += get_skip(type[0]);
	value[1] = get_param_raw_value(env, process->pc + skip, type[1], OP_XOR);
	skip += get_skip(type[1]);
	value[2] = get_param_raw_value(env, process->pc + skip, type[2], OP_XOR);
	if (!(is_reg(value[2])
		&& (type[0] != T_REG || is_reg(value[0]))
		&& (type[1] != T_REG || is_reg(value[1]))))
		return (1);
	value[0] = get_value(type[0], value[0], process, env);
	value[1] = get_value(type[1], value[1], process, env);
	process->reg[value[2] - 1] = (value[0] ^ value[1]);
	return ((process->reg[value[2] - 1] == 0) ? 0 : 1);
}
