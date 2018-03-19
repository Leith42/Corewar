/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:56:02 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/19 17:23:29 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	do_zjmp(t_process *process, t_env *env)
{
	if (process->carry == 1)
	{
		process->pc += (((short)get_param_raw_value(env, process->pc + 1,
			T_DIR, OP_ZJMP)) % IDX_MOD);
		process->pc %= MEM_SIZE;
	}
	return (0);
}
