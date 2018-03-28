/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/28 20:11:09 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
** For each process, in order, executes the current instruction by calling
** the associated function.
** Sets the generic values it can.
*/

static void		exec_inst(t_env *env, t_process *process)
{
	unsigned int	new_pc;
	int				ret;

	if (process->cur_opcode > 16 || process->cur_opcode == 0)
	{
		process->pc++;
		process->pc %= MEM_SIZE;
		process->cur_opcode = env->arena[process->pc];
		process->cycle_to_wait = 1;
		if (process->cur_opcode < 16 && process->cur_opcode > 0)
			process->cycle_to_wait = g_op_tab[process->cur_opcode - 1].cycle_nb;
		return ;
	}
	new_pc = 0;
	if (process->cur_opcode != OP_ZJMP || process->carry == 0)
		new_pc = skip_pc(env, process);
	ret = (*(env->exec_inst_tab[process->cur_opcode]))(process, env);
	if (process->cur_opcode != OP_ZJMP || process->carry == 0)
		process->pc = new_pc;
	if (g_op_tab[process->cur_opcode - 1].modif_carry == 1)
		process->carry = (ret == 0) ? 1 : 0;
}

static void		run_processes(t_env *env)
{
	t_list		*proc_lst;
	t_process	*proc;

	proc_lst = env->process;
	while (proc_lst && (proc = (t_process *)proc_lst->content))
	{
		proc->cycle_to_wait--;
		if (env->debug)
			disp_process_state(env, proc);
		if (proc->cycle_to_wait == 0)
			exec_inst(env, proc);
		proc_lst = proc_lst->next;
	}
	proc_lst = env->process;
	while (proc_lst && proc_lst->content)
	{
		if ((proc = ((t_process *)proc_lst->content))->cycle_to_wait == 0)
		{
			proc->cur_opcode = env->arena[proc->pc];
			proc->cycle_to_wait = 1;
			if (proc->cur_opcode < 16 && proc->cur_opcode > 0)
				proc->cycle_to_wait = g_op_tab[proc->cur_opcode - 1].cycle_nb;
		}
		proc_lst = proc_lst->next;
	}
}

/*
** Temporary function to skip unused cycles
*/

static size_t	skip_cycles(t_env *env, size_t max_skip)
{
	t_list		*lst;
	size_t		min_wait;

	min_wait = max_skip;
	if (env->is_dump_cycle_specified && env->dump_cycle < max_skip)
		min_wait = env->dump_cycle;
	if (min_wait < 3)
		return (0);
	lst = env->process;
	while (lst)
	{
		if (((t_process *)lst->content)->cycle_to_wait < min_wait)
			min_wait = ((t_process *)lst->content)->cycle_to_wait;
		if (min_wait < 3)
			return (0);
		lst = lst->next;
	}
	lst = env->process;
	while (lst)
	{
		((t_process *)lst->content)->cycle_to_wait -= (min_wait - 1);
		lst = lst->next;
	}
	env->dump_cycle -= (min_wait - 1);
	return (min_wait - 1);
}

static void		cycle_check(t_env *env)
{
	static size_t	nb_checks = 0;
	static size_t	cycle = 0;
	static size_t	global_cycle = 0;
	size_t			cycles_skipped;
	size_t			kill_proc;

	cycles_skipped = (env->debug) ? 0 :
		skip_cycles(env, env->cycle_to_die - cycle - 1);
	cycle += 1 + cycles_skipped;
	global_cycle += 1 + cycles_skipped;
	if (env->visual)
		disp_cycle_data(env, cycle, global_cycle, nb_checks);
	if (!(cycle >= env->cycle_to_die))
		return ;
	kill_proc = kill_dead_process(env);
	(env->visual) ? (void)ft_printf("\n\x1b[KProcesses killed at last check : \
%d\n\x1b[K", kill_proc) : (void)env;
	if ((env->nb_live >= NBR_LIVE || nb_checks >= MAX_CHECKS)
		&& !(nb_checks = 0))
		env->cycle_to_die -= (env->cycle_to_die <= CYCLE_DELTA) ?
			env->cycle_to_die : CYCLE_DELTA;
	else
		nb_checks++;
	env->nb_live = 0;
	cycle = 0;
}

/*
** Runs the battle.
*/

void			run(t_env *env)
{
	char	*winner;

	load_champions(env);
	if (env->visual)
		ft_putstr("\x1b[2J\x1b[68;0H");
	while (env->process != NULL)
	{
		if (env->is_dump_cycle_specified && env->dump_cycle-- == 0)
		{
			dump_memory(env, 64);
			return ;
		}
		run_processes(env);
		cycle_check(env);
		if (env->visual)
			disp_arena(env, 64);
		if (env->interactive)
			ft_pause(env);
	}
	if ((winner = get_champ_name(env, env->last_live_id)))
		ft_printf("Le joueur %d(%s) a gagne.\n",
				env->last_live_id, winner);
	else
		ft_printf("Personne n'a gagne.\n");
}
