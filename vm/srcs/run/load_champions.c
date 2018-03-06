/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:57:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 20:53:01 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loads champions in arena, with equally separated points of entry.
*/

void	load_champions(t_env *env)
{
	unsigned int	champ_nb;
	unsigned int	entry_point;
	unsigned int	end_point;
	t_process		*process;

	champ_nb = 0;
	end_point = 0;
	process = (t_process *)env->process;
	while (champ_nb < env->nb_of_champions)
	{

		entry_point = ((MEM_SIZE / env->nb_of_champions) * champ_nb);
		process->pc = entry_point;
		disp_arena_part(env, "\x1b[37m", end_point, entry_point);
		ft_memcpy(env->arena + entry_point,
				env->champions[champ_nb].program,
				env->champions[champ_nb].header.prog_size);
		end_point = entry_point + env->champions[champ_nb].header.prog_size;
		disp_arena_part(env, NULL, entry_point, end_point);
		champ_nb++;
		process = (t_process *)env->process->next;
	}
	disp_arena_part(env, "\x1b[37m", end_point, MEM_SIZE);
}
