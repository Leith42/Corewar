/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 22:41:23 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	init_champions(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->champions[i].id = 0;
		i++;
	}
}

void		init_env(t_env *env)
{
	env->dump_cycle = 0;
	env->nb_of_champions = 0;
	env->process = NULL;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->nb_live = 0;
	init_champions(env);
	ft_bzero(&(env->arena), sizeof(env->arena));
}
