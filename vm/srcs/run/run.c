/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 17:45:02 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Runs the battle.
** First initializes the arena and champions.
*/

/*
** while (1)
** {
** 	if (i == env->cycle_to_die)
** 		kill_dead_process(env);
** 	i++;
** }
*/

void	run(t_env *env)
{
	size_t	i;

	i = 0;
	load_champions(env);
	ft_putstr("\x1b[2J");
	while (1)
	{
		env->arena[i] += i % 7;
		env->mask[i] = i % 4 + 1;
		i += 7;
		i %= MEM_SIZE;
		disp_arena(env, 64);
	}
}
