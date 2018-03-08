/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/09 00:55:56 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

/*
** Displays current arena state in lines of line_len bytes in hex format.
*/

static char		*get_champ_color(t_env *env, unsigned int id)
{
	if (id == NULL_ID)
		return ("\x1b[2;37m");
	else if (id == env->champions[0].id)
		return (COLOR_P1);
	else if (env->nb_of_champions > 1 && id == env->champions[1].id)
		return (COLOR_P2);
	else if (env->nb_of_champions > 2 && id == env->champions[2].id)
		return (COLOR_P3);
	else if (env->nb_of_champions > 3 && id == env->champions[3].id)
		return (COLOR_P4);
	ft_putstr_fd("Bad ID in mask !\n", 2);
	exit(EXIT_FAILURE);
}

void			disp_arena(t_env *env, size_t line_len)
{
	size_t		i;

	i = 0;
	ft_putstr("\x1b[H");
	while (i < MEM_SIZE)
	{
		ft_printf("%s%02X \x1b[0m",
			get_champ_color(env, env->mask[i]), env->arena[i]);
		i++;
		if ((i % line_len) == 0)
			ft_putchar('\n');
	}
}

void			debug_actions(t_process *process, char *action)
{
	ft_printf("Le process appartenant à joueur %d effectue un %s      \n",
				process->champ_id, action);
}

unsigned int	ft_lstlen(t_list *lst)
{
	unsigned int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
