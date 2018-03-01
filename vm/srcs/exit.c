#include "vm.h"
#include <stdlib.h>
#include <zconf.h>

void	free_env(t_env env)
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

void	error_manager(t_env env, enum e_error signal)
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
		ft_putendl_fd("champions numbers must be positive integers.", STDERR_FILENO);
	else if (signal == OPEN_FILE_FAILED)
		perror("occurred while attempting to open a champion's program");
	else if (signal == INVALID_FILE_EXTENSION)
		ft_putendl_fd("the file extension of the programs must be \".cor\".", STDERR_FILENO);
	else
		perror(NULL);
	ft_putendl(VM_USAGE);
	exit(EXIT_FAILURE);
}
