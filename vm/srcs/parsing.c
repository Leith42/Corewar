#include "vm.h"

size_t		get_dump_cycle(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] != NULL)
	{
		if (ft_isdigit((int)arg[i]) == false)
		{
			//Todo: Temporary error handling (see exit.c).
			ft_putendl_fd("Error: invalid number of cycles.", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ((size_t)ft_atoi(arg));
}

t_env		parse_argv(char **argv)
{
	t_env		env;
	size_t		i;

	ft_bzero(&env, sizeof(t_env));
	i = 1;
	while(argv[i] != NULL)
	{
		if (ft_strequ(argv[i], "-dump") == true)
			env.options.dump_cycle = get_dump_cycle(argv[++i]);
		else if(ft_strequ(argv[i], "-n") == true) {}
			// Todo: Create a champion with custom id.
		i++;
	}
	return (env);
}
