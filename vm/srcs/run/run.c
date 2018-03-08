/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/08 21:46:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** For each process, in order, executes the current instruction by calling
** the associated function.
*/

static void	run_processes(t_env *env)
{
	t_list		*list_of_processes;
	t_process	*process;
	size_t		opcode;

	list_of_processes = env->process;
	while (list_of_processes)
	{
		process = (t_process *)list_of_processes->content;
		opcode = env->arena[process->pc];
		if (opcode - 1 < 16)
			(*(env->op_tab[opcode - 1]))(process, env);
		else
			debug_actions(process, "bad opcode");
		list_of_processes = list_of_processes->next;
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

void		run(t_env *env)
{
	size_t	cycle;
	size_t	nb_checks;

	load_champions(env);
	ft_putstr("\x1b[2J");
	cycle = 0;
	nb_checks = 0;
	while (env->process != NULL)
	{
		disp_arena(env, 64);
		ft_printf("\n\x1b[KCycle = %d\tCycle to die = %d\n\
\x1b[Knb_live = %d, checks = %d\n",
				cycle, env->cycle_to_die,
				env->nb_live, nb_checks);
		run_processes(env);
		cycle++;
		if (env->is_dump_cycle_specified && env->dump_cycle-- == 0)
		{
			ft_putstr("\x1b[2J");
			disp_arena(env, DUMP_LINE_LEN);
			break ;
		}
		if (cycle >= env->cycle_to_die)
		{
			if (env->nb_live >= NBR_LIVE || nb_checks == MAX_CHECKS)
			{
				if (env->cycle_to_die <= CYCLE_DELTA)
					env->cycle_to_die = 0;
				else
					env->cycle_to_die -= CYCLE_DELTA;
				nb_checks = 0;
			}
			else
				nb_checks++;
			env->nb_live = 0;
			cycle = 0;
		}
	}
}
