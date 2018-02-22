#include "vm.h"

void	debug(t_env env)
{
	size_t i = 0;

	printf("Champions amount: %zu\n", env.nb_of_champions);
	while (i < env.nb_of_champions)
	{
		printf("%d\n", env.champions[i].id);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_env		env;

	env = parse_argv(argv + 1);
	debug(env);

	return (EXIT_SUCCESS);
}
