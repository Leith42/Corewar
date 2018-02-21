#include "vm.h"

void	error_manager(enum e_error signal)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (signal == INVALID_NB_OF_CYCLES)
		ft_putendl_fd("invalid number of cycles.", STDERR_FILENO);
	else if (signal == INVALID_NB_OF_CHAMPIONS)
		ft_putendl_fd("too many champions.", STDERR_FILENO);
	else if (signal == INVALID_CHAMPION_ID)
		ft_putendl_fd("champions numbers must be positive integers.", STDERR_FILENO);
	exit(EXIT_FAILURE);
}