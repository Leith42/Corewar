/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 16:27:27 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Displays current arena state in lines of line_len bytes in hex format.
*/

void	disp_arena(t_env *env, size_t line_len)
{
	size_t	i;
	char	colors[5][12] = {
		"\x1b[2;37m",
		"\x1b[0;31m",
		"\x1b[0;32m",
		"\x1b[0;33m",
		"\x1b[0;34m"};

	i = 0;
	ft_putstr("\x1b[H");
	while (i < MEM_SIZE)
	{
		ft_printf("%s%02X \x1b[0m", colors[env->mask[i]], env->arena[i]);
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
