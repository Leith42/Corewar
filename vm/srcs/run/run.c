/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/09 02:01:28 by gudemare         ###   ########.fr       */
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
		if (opcode <= 16)
			(*(env->exec_inst_tab[opcode]))(process, env);
		else
			debug_actions(process, "bad opcode");
		list_of_processes = list_of_processes->next;
	}
}

static void	cycle_check(t_env *env)
{
	static size_t	nb_checks = 0;
	static size_t	cycle = 0;

	cycle++;
	ft_printf("\x1b[K\n\x1b[KCycle = %d\tCycle to die = %d\n\
\x1b[Knb_live = %d, checks = %d\n\x1b[KProcesses : %d\n\x1b[K",
			cycle, env->cycle_to_die, env->nb_live, nb_checks,
			ft_lstlen(env->process));
	if (cycle >= env->cycle_to_die)
	{
		if (env->nb_live >= NBR_LIVE || nb_checks >= MAX_CHECKS)
		{
			ft_printf("\x1b[KProcesses killed at last check : %d\n\x1b[K",
					kill_dead_process(env));
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

/*
** Runs the battle.
*/

void		run(t_env *env)
{
	char	*winner;

	load_champions(env);
	ft_putstr("\x1b[2J");
	while (env->process != NULL)
	{
		disp_arena(env, 64);
		run_processes(env);
		cycle_check(env);
		if (env->is_dump_cycle_specified && env->dump_cycle-- == 0)
		{
			ft_putstr("\x1b[2J");
			disp_arena(env, DUMP_LINE_LEN);
			break ;
		}
	}
	if ((winner = get_champ_name(env, env->last_live_id)))
		ft_printf("\x1b[2JLe joueur %d(%s) a gagne.\n",
				env->last_live_id, winner);
	else
		ft_printf("\x1b[2JPersonne n'a gagne.\n");
}
