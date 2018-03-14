/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:54:41 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/14 22:51:16 by gudemare         ###   ########.fr       */
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
	fork->pc = (process->pc + param) % MEM_SIZE;
	return (0);
}
