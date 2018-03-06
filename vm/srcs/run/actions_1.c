/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:53:08 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/06 22:51:56 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** List of actions that can be performed by the process
*/

void	do_live(t_process *process, t_env *env)
{
	debug_actions(process, "live");
	env->nb_live++;
	if (env->nb_live == NBR_LIVE && process_are_alive(env))
		env->cycle_to_die -= CYCLE_DELTA;
	(void)env;
}

void	do_ld(t_process *process, t_env *env)
{
	debug_actions(process, "ld");
	(void)env;
}

void	do_st(t_process *process, t_env *env)
{
	debug_actions(process, "st");
	(void)env;
}

void	do_zjmp(t_process *process, t_env *env)
{
	debug_actions(process, "zjmp");
	(void)env;
}

void	do_ldi(t_process *process, t_env *env)
{
	debug_actions(process, "ldi");
	(void)env;
}
