/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 09:57:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 10:49:45 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loads champions in arena, with equally separated points of entry.
*/

void	load_champions(t_env *env)
{
	unsigned int	champ_nb;

	champ_nb = 0;
	while (env->champions[champ_nb].id > 0)
	{
		ft_memcpy(env->arena + ((MEM_SIZE / env->nb_of_champions) * champ_nb),
				env->champions[champ_nb].program,
				env->champions[champ_nb].header.prog_size);
		champ_nb++;
	}
}
