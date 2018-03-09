/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:57:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 19:38:12 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loads champions in arena, with equally separated points of entry.
** Initializes mask ID values.
*/

void				load_champions(t_env *env)
{
	unsigned int	champ_nb;
	unsigned int	entry_point;
	unsigned int	end_point;
	t_process		*process;
	t_list			*lst_process;

	entry_point = 0;
	while (entry_point < MEM_SIZE)
		env->mask[entry_point++] = NULL_ID;
	champ_nb = 0;
	lst_process = env->process;
	while (champ_nb < env->nb_of_champions)
	{
		process = (t_process *)lst_process->content;
		entry_point = ((MEM_SIZE / env->nb_of_champions) * champ_nb);
		process->pc = entry_point;
		end_point = entry_point + env->champions[champ_nb].header.prog_size;
		ft_memcpy(env->arena + entry_point,
				env->champions[champ_nb].program,
				env->champions[champ_nb].header.prog_size);
		while (entry_point < end_point)
			env->mask[entry_point++] = env->champions[champ_nb].id;
		champ_nb++;
		lst_process = lst_process->next;
	}
}
