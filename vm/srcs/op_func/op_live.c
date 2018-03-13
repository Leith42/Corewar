/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:03 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/13 23:10:04 by gudemare         ###   ########.fr       */
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
	if ((champion_name = get_champ_name(env, param)))
		ft_printf("A process report that the champion %s (%u) is alive.\n",
					champion_name, param);
	process->is_alive = true;
	env->last_live_id = param;
	env->nb_live++;
	process->pc += 1 + 4;
	return (0);
}
