/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:54:41 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/21 21:07:33 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_lfork(t_process *process, t_env *env)
{
	unsigned int	param;
	t_process		*fork;

	param = get_param_raw_value(env, process->pc + 1, T_DIR, OP_LFORK);
	add_new_process(env, process->champ_id);
	fork = (t_process *)env->process->content;
	memcpy(fork, process, sizeof(t_process));
	if (process->aff_buffer != NULL)
	{
		if ((fork->aff_buffer = ft_strdup(process->aff_buffer)) == NULL)
		{
			ft_free_exit(*env, NULL, true, false);
		}
	}
	fork->pc = (process->pc + param) % MEM_SIZE;
	fork->cur_opcode = env->arena[fork->pc];
	if (fork->cur_opcode > 16 || fork->cur_opcode == 0)
		fork->cycle_to_wait = 0;
	else
		fork->cycle_to_wait = g_op_tab[fork->cur_opcode - 1].cycle_nb;
	return (0);
}
