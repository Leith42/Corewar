/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:03 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/13 19:56:41 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The advancement of the PC is to be made more generic.
*/

int		do_live(t_process *process, t_env *env)
{
	unsigned int	param;
	char			*champion_name;

	param = get_param_raw_value(env, process->pc + 1, T_DIR, OP_LIVE);
	champion_name = get_champ_name(env, param);
	if (champion_name != NULL)
	{
		ft_printf("A process report that the champion %s (%u) is alive.\n",
					champion_name, param);
	}
	process->is_alive = true;
	process->pc += 4 + 1;
	process->pc %= MEM_SIZE;
	env->last_live_id = param;
	env->nb_live++;
	return (0);
}
