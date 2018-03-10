/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/10 04:21:41 by gudemare         ###   ########.fr       */
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
	env->exec_inst_tab[OP_LIVE] = do_live;
	env->exec_inst_tab[OP_LD] = do_ld;
	env->exec_inst_tab[OP_ST] = do_st;
	env->exec_inst_tab[OP_ADD] = do_zjmp;
	env->exec_inst_tab[OP_SUB] = do_ldi;
	env->exec_inst_tab[OP_AND] = do_add;
	env->exec_inst_tab[OP_OR] = do_sub;
	env->exec_inst_tab[OP_XOR] = do_and;
	env->exec_inst_tab[OP_ZJMP] = do_or;
	env->exec_inst_tab[OP_LDI] = do_xor;
	env->exec_inst_tab[OP_STI] = do_sti;
	env->exec_inst_tab[OP_FORK] = do_fork;
	env->exec_inst_tab[OP_LLD] = do_lld;
	env->exec_inst_tab[OP_LLDI] = do_lldi;
	env->exec_inst_tab[OP_LFORK] = do_lfork;
	env->exec_inst_tab[OP_AFF] = do_aff;
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
