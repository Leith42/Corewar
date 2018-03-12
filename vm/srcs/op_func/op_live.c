/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:03 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/12 22:11:06 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	env->last_live_id = param;
	env->nb_live++;
	return (0);
}
