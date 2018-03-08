/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/08 19:07:57 by gudemare         ###   ########.fr       */
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

static void	init_op_tab(t_env *env)
{
	env->op_tab[0] = do_live;
	env->op_tab[1] = do_ld;
	env->op_tab[2] = do_st;
	env->op_tab[3] = do_zjmp;
	env->op_tab[4] = do_ldi;
	env->op_tab[5] = do_add;
	env->op_tab[6] = do_sub;
	env->op_tab[7] = do_and;
	env->op_tab[8] = do_or;
	env->op_tab[9] = do_xor;
	env->op_tab[10] = do_sti;
	env->op_tab[11] = do_fork;
	env->op_tab[12] = do_lld;
	env->op_tab[13] = do_lldi;
	env->op_tab[14] = do_lfork;
	env->op_tab[15] = do_aff;
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
	init_op_tab(env);
	ft_bzero(&(env->arena), sizeof(env->arena));
}

t_process	*init_process(t_env *env, unsigned int champion_id)
{
	t_process	*process;
	size_t		i;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		ft_free_exit(*env, NULL, 1, 0);
	process->reg[0] = champion_id;
	i = 1;
	while (i < REG_NUMBER)
		process->reg[i++] = 0;
	process->champ_id = champion_id;
	return (process);
}
