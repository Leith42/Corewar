/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:53:08 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/06 19:18:35 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** List of actions that can be performed by the process
*/

void	do_live(t_process process, t_env env)
{
	debug_actions(process, "live");
	(void)env;
}

void	do_ld(t_process process, t_env env)
{
	debug_actions(process, "ld");
	(void)env;
}

void	do_st(t_process process, t_env env)
{
	debug_actions(process, "st");
	(void)env;
}

void	do_zjmp(t_process process, t_env env)
{
	debug_actions(process, "zjmp");
	(void)env;
}

void	do_ldi(t_process process, t_env env)
{
	debug_actions(process, "ldi");
	(void)env;
}
