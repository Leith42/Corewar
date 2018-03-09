/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:15:13 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/09 00:00:50 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** zconf.h is included for its STDERR_X in signal handling.
*/

#include "vm.h"
#include <stdlib.h>
#include <zconf.h>

static void		free_process(void *process, size_t size)
{
	(void)size;
	free((t_process*)process);
}

void			free_env(t_env env)
{
	if (env.process)
		ft_lstdel(&(env.process), &free_process);
}

/*
**	Basic error handling.
**	Take a signal, displays an appropriate error message on STDERR and exit.
*/

void			ft_free_exit(t_env env, char *error,
				bool disp_errno, bool disp_usage)
{
	free_env(env);
	if (error != NULL)
		ft_dprintf(2, "ERROR : %s\n", error);
	if (disp_errno == true)
		perror("Corewar");
	if (disp_usage == true)
		ft_dprintf(2, "Usage: ./corewar \
[-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
	exit(EXIT_FAILURE);
}
