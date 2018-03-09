/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:39 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/09 01:57:08 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

int			main(int argc, char *argv[])
{
	t_env		env;

	if (argc < 2)
	{
		ft_putendl("Usage: ./corewar \
[-dump nbr_cycles] [[-n number] champion1.cor] ...");
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
