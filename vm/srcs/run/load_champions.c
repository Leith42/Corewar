/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:57:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/16 23:02:32 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loads champions in arena, with equally separated points of entry.
** Initializes mask ID values.
** The get_next_proc_backwards is a bad hack needed because the process list
** needs to be created backwards.
*/

static t_process	*get_next_proc_backwards(t_env *env, unsigned int champ_nb)
{
	t_list	*ret;

	ret = env->process;
	while (champ_nb < env->nb_of_champions - 1)
	{
		ret = ret->next;
		champ_nb++;
	}
	return ((t_process *)ret->content);
}

void				load_champions(t_env *env)
{
	unsigned int	champ_nb;
	unsigned int	entry_point;
	unsigned int	end_point;
	t_process		*process;

	entry_point = 0;
	while (entry_point < MEM_SIZE)
		env->mask[entry_point++] = NULL_ID;
	champ_nb = 0;
	while (champ_nb < env->nb_of_champions)
	{
		process = get_next_proc_backwards(env, champ_nb);
		entry_point = ((MEM_SIZE / env->nb_of_champions) * champ_nb);
		process->pc = entry_point;
		end_point = entry_point + env->champions[champ_nb].header.prog_size;
		ft_memcpy(env->arena + entry_point,
				env->champions[champ_nb].program,
				env->champions[champ_nb].header.prog_size);
		while (entry_point < end_point)
			env->mask[entry_point++] = env->champions[champ_nb].id;
		champ_nb++;
	}
}
