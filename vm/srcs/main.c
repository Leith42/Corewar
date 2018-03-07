/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:21:39 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 19:38:40 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

static void	debug(t_env env)
{
	size_t		i;
	t_process	*process;
	t_list		*lst_process;

	i = 0;
	lst_process = env.process;
	ft_printf("Champions amount: %zu\n", env.nb_of_champions);
	while (i < env.nb_of_champions)
	{
		process = (t_process *)lst_process->content;
		ft_printf("\n");
		ft_printf("Champion ID : %d\n", env.champions[i].id);
		ft_printf("Process ID: %d\n", process->reg[0]);
		ft_printf("Magic number: %d\n", env.champions[i].header.magic);
		ft_printf("Prog size: %d\n", env.champions[i].header.prog_size);
		ft_printf("Name: %s\n", env.champions[i].header.prog_name);
		ft_printf("Comment: %s\n", env.champions[i].header.comment);
		ft_printf("Program: %s\n", env.champions[i].program);
		ft_printf("PC: %u\n", process->pc);
		ft_printf("champ_id: %u\n", process->champ_id);
		lst_process = lst_process->next;
		i++;
	}
}

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
		debug(env);
		free_env(env);
	}
	return (EXIT_SUCCESS);
}
