/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:57:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 11:59:33 by gudemare         ###   ########.fr       */
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

	champ_nb = 0;
	while (champ_nb < env->nb_of_champions)
	{
		entry_point = ((MEM_SIZE / env->nb_of_champions) * champ_nb);
		ft_memcpy(env->arena + entry_point,
				env->champions[champ_nb].program,
				env->champions[champ_nb].header.prog_size);
		champ_nb++;
	}
}
