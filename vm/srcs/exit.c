#include "vm.h"

void	error_manager(enum e_error signal)
{
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
	ft_putendl(VM_USAGE);
	exit(EXIT_FAILURE);
}
