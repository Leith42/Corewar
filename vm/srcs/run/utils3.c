/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:52:01 by gudemare          #+#    #+#             */
/*   Updated: 2018/04/04 22:57:23 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	set_process_instruction(t_env *env, t_process *process)
{
	process->cur_opcode = env->arena[process->pc];
	process->cycle_to_wait = 1;
	if (process->cur_opcode < 16 && process->cur_opcode > 0)
		process->cycle_to_wait = g_op_tab[process->cur_opcode - 1].cycle_nb;
}
