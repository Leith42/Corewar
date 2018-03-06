/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:30:29 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/06 19:19:53 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** List of actions that can be performed by the process
*/

void	do_sti(t_process process, t_env env)
{
	debug_actions(process, "sti");
	(void)env;
}

void	do_fork(t_process process, t_env env)
{
	debug_actions(process, "fork");
	(void)env;
}

void	do_lld(t_process process, t_env env)
{
	debug_actions(process, "lld");
	(void)env;
}


void	do_lldi(t_process process, t_env env)
{
	debug_actions(process, "lldi");
	(void)env;
}

void	do_lfork(t_process process, t_env env)
{
	debug_actions(process, "lfork");
	(void)env;
}
