/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 19:47:32 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Displays current arena state in lines of line_len bytes in hex format.
*/

void	disp_arena_part(t_env *env, char *color, size_t start, size_t end)
{
	if (color)
		ft_printf("%s", color);
	else if (start < MEM_SIZE / env->nb_of_champions)
		ft_printf("\x1b[31m");
	else if (start < (MEM_SIZE / env->nb_of_champions) * 2)
		ft_printf("\x1b[32m");
	else if (start < (MEM_SIZE / env->nb_of_champions) * 3)
		ft_printf("\x1b[33m");
	else if (start < (MEM_SIZE / env->nb_of_champions) * 4)
		ft_printf("\x1b[34m");
	while (start < end)
	{
		ft_printf("%02X ", env->arena[start++]);
		if ((start % 64) == 0)
			ft_putchar('\n');
	}
	ft_printf("\x1b[0m");
}

void	disp_arena(t_env *env, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02X ", env->arena[i]);
		i++;
		if ((i % line_len) == 0)
			ft_putchar('\n');
	}
}

void	debug_actions(t_process *process, char *action)
{
	ft_printf("Le process appartenant à joueur %d effectue un %s",
				process->champ_id, action);
}
