#include "vm.h"
#include <stdlib.h>
#include <stdio.h>

void	debug(t_env env)
{
	size_t i = 0;

	ft_printf("Champions amount: %zu\n", env.nb_of_champions);
	while (i < env.nb_of_champions)
	{
		printf("\n");
		printf("Champion ID : %d\n", env.champions[i].id);
		printf("Process ID: %d\n", env.process->reg[0]);
		printf("Magic number: %d\n", env.champions[i].header.magic);
		printf("Prog size: %d\n", env.champions[i].header.prog_size);
		printf("Name: %s\n", env.champions[i].header.prog_name);
		printf("Comment: %s\n", env.champions[i].header.comment);
		printf("Program: %s\n", env.champions[i].program);
		env.process = env.process->next;
		i++;
	}
}

int		main(int argc, char *argv[])
{
	t_env		env;

	if (argc < 2)
	{
		ft_putendl(VM_USAGE);
	}
	else
	{
		init_env(&env);
		parse_argv(&env, argv + 1);
		debug(env);
		free_env(env);
	}
	return (EXIT_SUCCESS);
}
