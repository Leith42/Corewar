/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 21:09:39 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** For each process, in order, executes the current instruction by calling
** the associated function.
** IS NOT PROTECTED FROM BAD OPCODES
*/

static void	run_processes(t_env *env)
{
	t_list		*lst;
	t_process	*process;

	lst = env->process;
	while (lst)
	{
		process = (t_process *)lst->content;
		(*(env->op_tab[env->arena[process->pc] - 1]))(process, env);
		lst = lst->next;
	}
}

/*
** Runs the battle.
** First initializes the arena and champions.
** Then resets the screen.
** Then runs the battle, running instructions and displaying arena.
*/

/*
** while (1)
** {
** 	if (i == env->cycle_to_die)
** 		kill_dead_process(env);
** 	i++;
** }
*/

/*
** DOES NOT DUMP if dump_cycle = 0 ! Needs var saying -dump is in argv
** kill_all_process() should replace break calls for leaks and sanity
*/

void		run(t_env *env)
{
	size_t	cycle;

	load_champions(env);
	ft_putstr("\x1b[2J");
	cycle = 0;
	while (env->process)
	{
		disp_arena(env, 64);
		ft_printf("\n\x1b[KCycle = %d\tCycle to die = %d\n",
				cycle, env->cycle_to_die);
		run_processes(env);
		cycle++;
		env->dump_cycle--;
		if (env->dump_cycle == 0)
		{
			ft_putstr("\x1b[2J");
			disp_arena(env, DUMP_LINE_LEN);
			break ;
		}
	}
}
