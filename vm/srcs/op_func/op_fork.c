/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:53:50 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/14 00:35:49 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_fork(t_process *process, t_env *env)
{
	short			param;
	t_process		*fork;

	param = (short)get_param_raw_value(env, process->pc + 1, T_DIR, OP_FORK);
	fork = add_new_process(env, process->champ_id);
	memcpy(fork, process, sizeof(t_process));
	fork->pc = process->pc + (param % IDX_MOD);
	return (0);
}
