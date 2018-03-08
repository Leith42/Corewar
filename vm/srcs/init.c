/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/08 22:44:10 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

static void	init_champions(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_memset(&env->champions[i], '\0', sizeof(t_champion));
		i++;
	}
}

static void	init_exec_inst_tab(t_env *env)
{
	env->exec_inst_tab[0] = do_bad_opc;
	env->exec_inst_tab[1] = do_live;
	env->exec_inst_tab[2] = do_ld;
	env->exec_inst_tab[3] = do_st;
	env->exec_inst_tab[4] = do_zjmp;
	env->exec_inst_tab[5] = do_ldi;
	env->exec_inst_tab[6] = do_add;
	env->exec_inst_tab[7] = do_sub;
	env->exec_inst_tab[8] = do_and;
	env->exec_inst_tab[9] = do_or;
	env->exec_inst_tab[10] = do_xor;
	env->exec_inst_tab[11] = do_sti;
	env->exec_inst_tab[12] = do_fork;
	env->exec_inst_tab[13] = do_lld;
	env->exec_inst_tab[14] = do_lldi;
	env->exec_inst_tab[15] = do_lfork;
	env->exec_inst_tab[16] = do_aff;
}

void		init_env(t_env *env)
{
	env->dump_cycle = 0;
	env->is_dump_cycle_specified = false;
	env->nb_of_champions = 0;
	env->process = NULL;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->nb_live = 0;
	init_champions(env);
	init_exec_inst_tab(env);
	ft_bzero(&(env->arena), sizeof(env->arena));
}

void		add_new_process(t_env *env, unsigned int champion_id)
{
	t_process	*process;
	t_list		*tmp;
	size_t		i;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		ft_free_exit(*env, NULL, 1, 0);
	process->reg[0] = champion_id;
	i = 1;
	while (i < REG_NUMBER)
		process->reg[i++] = 0;
	process->champ_id = champion_id;
	if (!(tmp = ft_lstnew((void *)process, sizeof(t_process))))
		ft_free_exit(*env, NULL, 1, 0);
	ft_lstpush_front(&(env->process), tmp);
}
