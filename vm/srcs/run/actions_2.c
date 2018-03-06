/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:30:18 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/06 19:46:01 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** List of actions that can be performed by the process
*/

void	do_add(t_process *process, t_env *env)
{
	debug_actions(process, "add");
	(void)env;
}

void	do_sub(t_process *process, t_env *env)
{
	debug_actions(process, "sub");
	(void)env;
}

void	do_and(t_process *process, t_env *env)
{
	debug_actions(process, "and");
	(void)env;
}

void	do_or(t_process *process, t_env *env)
{
	debug_actions(process, "or");
	(void)env;
}

void	do_xor(t_process *process, t_env *env)
{
	debug_actions(process, "xor");
	(void)env;
}
