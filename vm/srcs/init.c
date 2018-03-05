/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:11 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/05 16:21:30 by gudemare         ###   ########.fr       */
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
//		env->champions[i].name[PROG_NAME_LENGTH] = '\0';
//		env->champions[i].comment[COMMENT_LENGTH] = '\0';
		i++;
	}
}

void		init_env(t_env *env)
{
	env->dump_cycle = 0;
	env->nb_of_champions = 0;
	env->process = NULL;
	init_champions(env);
	ft_bzero(&(env->arena), sizeof(env->arena));
}
