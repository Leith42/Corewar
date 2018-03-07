/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:55:03 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 23:55:17 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	do_live(t_process *process, t_env *env)
{
	debug_actions(process, "live");
	env->nb_live++;
	if (env->nb_live == NBR_LIVE && process_are_alive(env))
		env->cycle_to_die -= CYCLE_DELTA;
	(void)env;
}
