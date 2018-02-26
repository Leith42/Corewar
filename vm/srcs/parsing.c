#include "vm.h"

static size_t	get_dump_cycle(char **argv, size_t *i)
{
	int	cycles;

	if (argv[*i + 1] == NULL || is_string_numeric(argv[*i + 1]) == false)
	{
		error_manager(INVALID_NB_OF_CYCLES);
	}
	cycles = ft_atoi(argv[*i + 1]);
	*i += 2;
	return ((size_t)cycles);
}

t_env			parse_argv(char **argv)
{
	t_env		env;
	size_t		i;
	char		*custom_id;

	i = 0;
	init_env(&env);
	if (ft_strequ(argv[0], "-dump") == true)
		env.dump_cycle = get_dump_cycle(argv, &i);
	while (argv[i])
	{
		custom_id = NULL;
		if (ft_strequ(argv[i], "-n") == true)
		{
			argv[i + 1] != NULL ? custom_id = argv[i + 1] : error_manager(INVALID_CHAMPION_ID);
			i += 2;
		}
		if (env.nb_of_champions < MAX_PLAYERS)
			parse_champion(&env, custom_id, argv[i]);
		else
			error_manager(TOO_MANY_CHAMPIONS);
		i++;
	}
	if (env.nb_of_champions == 0)
		error_manager(NO_CHAMPIONS);
	return (env);
}
