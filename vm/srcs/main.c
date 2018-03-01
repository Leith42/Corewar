#include "vm.h"

void	debug(t_env env)
{
	size_t i = 0;

	printf("Champions amount: %zu\n", env.nb_of_champions);
//	while (i < env.nb_of_champions)
//	{
//		printf("Champion ID : %d\n", env.champions[i].id);
//		printf("Process ID: %d\n", env.process->reg[0]);
//		printf("\n");
//		env.process = env.process->next;
//		i++;
//	}
	while(i < REG_NUMBER && env.process)
	{
		printf("%zu->%d ", i + 1, env.process->reg[i]);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	t_env		env;

	if (argc < 2)
		ft_putendl(VM_USAGE);
	else
	{
		env = parse_argv(argv + 1);
		debug(env);
		free_env(env);
	}
	return (EXIT_SUCCESS);
}
