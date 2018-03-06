/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 00:11:19 by mgonon           ###   ########.fr       */
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
}
