/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:21:38 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/27 18:23:46 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		set_mask_id(t_env *env, t_process *process,
				unsigned int param_len)
{
	if (env->arena[process->pc] == OP_LIVE)
		return ;
	while (--param_len > 0)
		env->mask[(process->pc + param_len) % MEM_SIZE] = process->champ_id;
	env->mask[process->pc % MEM_SIZE] = process->champ_id;
}

/*
** Advances PC by length of parameters indicated by the OCP.
** If no OCP is on the instruction, it advances by T_DIR size.
*/

unsigned int	skip_pc(t_env *env, t_process *process)
{
	unsigned int	param_len;
	unsigned int	cur;
	unsigned int	cur_type;

	if (g_op_tab[process->cur_opcode - 1].ocp == true)
	{
		param_len = 2;
		cur = 0;
		while (cur < g_op_tab[process->cur_opcode - 1].nb_of_params)
		{
			cur_type = get_param_type(env, process->pc, 0x00, cur);
			if (cur_type == T_DIR)
				param_len += (g_op_tab[process->cur_opcode - 1].addr_or_nb
						== true) ? 2 : 4;
			else
				param_len += (cur_type == T_IND) ? 2 : cur_type;
			cur++;
		}
	}
	else
		param_len = 1 + (
			(g_op_tab[process->cur_opcode - 1].addr_or_nb == true) ? 2 : 4);
	set_mask_id(env, process, param_len);
	return ((process->pc + param_len) % MEM_SIZE);
}

unsigned int	is_reg(unsigned int value)
{
	return (value > 0 && value <= REG_NUMBER);
}
