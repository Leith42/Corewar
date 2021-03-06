/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:39 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/13 23:03:32 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

void		print_usage(void)
{
	ft_putendl("Usage: ./corewar \
[-dump nbr_cycles] [-v] [-i] [-d] [-a] [-c] [[-n number] champion1.cor] ...");
	ft_putendl("-dump\t : Dumps memory after N cycles then exits.");
	ft_putendl("-n\t : Specify a custom champion ID.");
	ft_putendl("-a\t : Prints output from \"aff\" (default is to hide it).");
	ft_putendl("-v\t : Graphic mode.");
	ft_putendl("-i\t : Interactive mode.");
	ft_putendl("-d\t : Debug mode.");
	ft_putendl("-c\t : Comparison mode. "
			"Dumps will display 64 bytes per line instead of 32.");
	ft_putendl("--no-skip: Disable skip of unused cycles.");
}

int			main(int argc, char *argv[])
{
	t_env		env;

	if (argc < 2)
	{
		print_usage();
	}
	else if (sizeof(int) != 4 || sizeof(short) != 2)
	{
		ft_dprintf(2, "ERROR : int or short size is not the expected size. \
Aborting.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		init_env(&env);
		parse_argv(&env, argv + 1);
		run(&env);
		free_env(env);
	}
	return (EXIT_SUCCESS);
}
