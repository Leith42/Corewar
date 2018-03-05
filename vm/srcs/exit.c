/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:15:13 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/05 16:21:02 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>
#include <zconf.h>

void		free_env(t_env env)
{
	while (env.process)
	{
		free(env.process);
		env.process = env.process->next;
	}
}

/*
**	Basic error handling.
**	Take a signal, displays an appropriate error message on STDERR and exit.
*/

static void	error_manager_bis(t_env env, enum e_error signal)
{
	if (signal == READ_FILE_FAILED)
		ft_putendl_fd("occurred while attempting to read a champion's program.",
				STDERR_FILENO);
	else if (signal == FILE_IS_TOO_BIG)
		ft_putendl_fd("a champion's program is too big.", STDERR_FILENO);
	else if (signal == NOT_A_CHAMPION_FILE)
		ft_putendl_fd("please make sure the files are Corewar champions.",
				STDERR_FILENO);
	else
		perror(NULL);
}

void		error_manager(t_env env, enum e_error signal)
{
	free_env(env);
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (signal == INVALID_NB_OF_CYCLES)
		ft_putendl_fd("invalid number of cycles.", STDERR_FILENO);
	else if (signal == TOO_MANY_CHAMPIONS)
		ft_putendl_fd("too many champions.", STDERR_FILENO);
	else if (signal == NO_CHAMPIONS)
		ft_putendl_fd("no champions.", STDERR_FILENO);
	else if (signal == INVALID_CHAMPION_ID)
		ft_putendl_fd("champions numbers must be positive integers.",
				STDERR_FILENO);
	else if (signal == OPEN_FILE_FAILED || signal == CLOSE_FILE_FAILED)
		perror("occurred while attempting to open a champion's program");
	else if (signal == INVALID_FILE_EXTENSION)
		ft_putendl_fd("the file extension of the programs must be \".cor\".",
				STDERR_FILENO);
	else if (signal == NB_OF_CYCLES_ALREADY_EXISTS)
		ft_putendl_fd("a number of cycles has already been specified.",
				STDERR_FILENO);
	else
		error_manager_bis(env, signal);
	ft_putendl(VM_USAGE);
	exit(EXIT_FAILURE);
}
