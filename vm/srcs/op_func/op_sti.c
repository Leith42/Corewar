/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:53:40 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/28 14:19:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG
*/

static void		do_sti_bis(t_env *env, t_process *process,
				unsigned short *type, unsigned int *val)
{
	unsigned int	start;

	if (type[1] != T_DIR)
		val[1] = (type[1] == T_REG) ? process->reg[val[1] - 1]
			: get_uintfrom_char(env, (process->pc +
			(((short)(val[1])) % IDX_MOD)) % MEM_SIZE, 4);
	if (type[1] == T_REG && type[2] == T_REG)
		start = ((process->pc +
				(((int)(val[1] + val[2])) % IDX_MOD)) % MEM_SIZE);
	else
		start = ((process->pc +
				(((short)(val[1] + val[2])) % IDX_MOD)) % MEM_SIZE);
	write_uint_to_char(env, start, 4, val[0]);
	env->mask[(start + 0) % MEM_SIZE] = process->champ_id;
	env->mask[(start + 1) % MEM_SIZE] = process->champ_id;
	env->mask[(start + 2) % MEM_SIZE] = process->champ_id;
	env->mask[(start + 3) % MEM_SIZE] = process->champ_id;
}

int				do_sti(t_process *process, t_env *env)
{
	unsigned short	type[3];
	unsigned int	val[3];

	type[1] = get_param_type(env, process->pc, OP_STI, 1);
	type[2] = get_param_type(env, process->pc, OP_STI, 2);
	val[0] = get_param_raw_value(env, process->pc + 2, T_REG, OP_STI);
	val[1] = get_param_raw_value(env, process->pc + 3, type[1], OP_STI);
	if (!(get_param_type(env, process->pc, OP_STI, 0) == T_REG && type[1] &
		g_op_tab[OP_STI - 1].param_type[1] && type[2] &
		g_op_tab[OP_STI - 1].param_type[2] && is_reg(val[0])
		&& (type[1] != T_REG || is_reg(val[1]))))
		return (0);
	val[0] = process->reg[val[0] - 1];
	val[2] = get_param_raw_value(env, process->pc + 3 +
			((type[1] == T_REG) ? 1 : 2), type[2], OP_STI);
	if (!(type[2] != T_REG || is_reg(val[2])))
		return (0);
	val[2] = (type[2] == T_REG) ? process->reg[val[2] - 1] : val[2];
	do_sti_bis(env, process, type, val);
	return (0);
}
