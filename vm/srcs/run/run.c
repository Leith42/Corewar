/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/23 00:27:59 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
** For each process, in order, executes the current instruction by calling
** the associated function.
** Sets the generic values it can.
*/

static void	exec_inst(t_env *env, t_process *process)
{
	unsigned int	new_pc;
	int				ret;

	ft_printf("\x1b[KLe process appartenant à joueur %d effectue un %s au pc = \
%d; reg = {%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x, %x,%x}  \n\x1b[K",
	process->champ_id, (process->cur_opcode > 16 || process->cur_opcode == 0) ?
	"bad opcode" : g_op_tab[process->cur_opcode - 1].name, process->pc,
	process->reg[0], process->reg[1], process->reg[2], process->reg[3],
	process->reg[4], process->reg[5], process->reg[6], process->reg[7],
	process->reg[8], process->reg[9], process->reg[10], process->reg[11],
	process->reg[12], process->reg[13], process->reg[14], process->reg[15]);
	if (process->cur_opcode > 16 || process->cur_opcode == 0)
	{
		process->pc++;
		process->pc %= MEM_SIZE;
		process->cur_opcode = env->arena[process->pc];
		process->cycle_to_wait = 0;
		return ;
	}
	new_pc = skip_pc(env, process);
	ret = (*(env->exec_inst_tab[process->cur_opcode]))(process, env);
	if (process->cur_opcode != OP_ZJMP || process->carry == 0)
		process->pc = new_pc;
	if (g_op_tab[process->cur_opcode - 1].modif_carry == 1)
		process->carry = (ret == 0) ? 1 : 0;
	process->cur_opcode = env->arena[process->pc];
	process->cycle_to_wait = 0;
	if (process->cur_opcode < 16 && process->cur_opcode > 0)
		process->cycle_to_wait = g_op_tab[process->cur_opcode - 1].cycle_nb;
}

static void	run_processes(t_env *env)
{
	t_list		*list_of_processes;
	t_process	*process;

	list_of_processes = env->process;
	while (list_of_processes)
	{
		process = (t_process *)list_of_processes->content;
		if (process->cycle_to_wait == 0)
			exec_inst(env, process);
		else
		{
			ft_printf("\x1b[KLe process appartenant à joueur %d doit encore \
attendre %d cycles. pc = %d reg = {%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,\
%x,%x}  \n\x1b[K", process->champ_id, process->cycle_to_wait, process->pc,
			process->reg[0], process->reg[1], process->reg[2], process->reg[3],
			process->reg[4], process->reg[5], process->reg[6], process->reg[7],
			process->reg[8], process->reg[9], process->reg[10],
			process->reg[11], process->reg[12], process->reg[13],
			process->reg[14], process->reg[15]);
			process->cycle_to_wait--;
		}
		list_of_processes = list_of_processes->next;
	}
}

/*
** Temporary function to skip unused cycles
*/

static unsigned int	skip_cycles(t_env *env)
{
	t_list			*lst;
	unsigned int	min_wait;

	min_wait = 1000;
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
	return (min_wait - 1);
}

static void	cycle_check(t_env *env)
{
	static size_t	nb_checks = 0;
	static size_t	cycle = 0;
	static size_t	global_cycle = 0;
	unsigned int	cycles_skipped; //

	cycles_skipped = skip_cycles(env);
	cycle += 1 + cycles_skipped;
	global_cycle += 1 + cycles_skipped;
	ft_printf("\n\x1b[K\n\x1b[K\n\x1b[K\x1b[KTotal cycles = %d\tCycles = %d\t\
Cycle to die = %d\n\x1b[Knb_live = %d, checks = %d\n\x1b[K\
Processes : %d\n\x1b[K",
			global_cycle, cycle, env->cycle_to_die, env->nb_live, nb_checks,
			ft_lstlen(env->process));
	if (!(cycle >= env->cycle_to_die))
		return ;
	ft_printf("\n\x1b[KProcesses killed at last check : %d\n\x1b[K",
			kill_dead_process(env));
	if (env->nb_live >= NBR_LIVE || nb_checks >= MAX_CHECKS)
	{
		env->cycle_to_die -= (env->cycle_to_die <= CYCLE_DELTA) ?
			env->cycle_to_die : CYCLE_DELTA;
		nb_checks = 0;
	}
	else
		nb_checks++;
	env->nb_live = 0;
	cycle = 0;
}

static void	init_processes_waits_and_opcodes(t_env *env)
{
	t_list		*proc_lst;
	t_process	*proc;

	proc_lst = env->process;
	while (proc_lst)
	{
		proc = (t_process *)proc_lst->content;
		proc->cycle_to_wait = g_op_tab[env->arena[proc->pc] - 1].cycle_nb;
		proc->cur_opcode = env->arena[proc->pc];
		proc_lst = proc_lst->next;
	}
}

/*
** Runs the battle.
*/

void		run(t_env *env)
{
	char	*winner;

	load_champions(env);
	init_processes_waits_and_opcodes(env);
	ft_putstr("\x1b[2J\x1b[68;0H");
	while (env->process != NULL)
	{
		run_processes(env);
		cycle_check(env);
		disp_arena(env, 64);
		if (env->is_dump_cycle_specified && env->dump_cycle-- == 0)
		{
			ft_putstr("\x1b[2J");
			disp_arena(env, DUMP_LINE_LEN);
			break ;
		}
		getchar();//REMOVE AFTER DEBUG
	}
	if ((winner = get_champ_name(env, env->last_live_id)))
		ft_printf("\x1b[2JLe joueur %d(%s) a gagne.\n",
				env->last_live_id, winner);
	else
		ft_printf("\x1b[2JPersonne n'a gagne.\n");
}
