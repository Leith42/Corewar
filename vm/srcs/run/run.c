/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:49:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 11:41:38 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Runs the battle.
** First initializes the arena and champions.
*/

void	run(t_env *env)
{
	load_champions(env);
	disp_arena(env, 64);
}
