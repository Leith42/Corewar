#include "vm.h"

/*
**	Ensure that the dump cycle is a positive integer and returns it.
*/

static size_t	get_dump_cycle(char **argv, size_t *pos, t_env env)
{
	int	cycles;

	if (env.dump_cycle)
	{
		error_manager(env, NB_OF_CYCLES_ALREADY_EXISTS);
	}
	if (argv[*pos + 1] == NULL || is_string_numeric(argv[*pos + 1]) == false)
	{
		error_manager(env, INVALID_NB_OF_CYCLES);
	}
	cycles = ft_atoi(argv[*pos + 1]);
	*pos += 2;
	return ((size_t)cycles);
}

/*
**	Starting point of the parsing.
**	Here we make sure that all arguments are valid.
**	Generates and return the main structure of Corewar (t_env).
*/

t_env			parse_argv(char **argv)
{
	t_env		env;
	size_t		pos;
	char		*custom_id;

	pos = 0;
	init_env(&env);
	while (argv[pos])
	{
		custom_id = NULL;
		if (ft_strequ(argv[pos], "-dump") == true)
			env.dump_cycle = get_dump_cycle(argv, &pos, env);
		if (argv[pos] == NULL)
			break;
		if (ft_strequ(argv[pos], "-n") == true)
		{
			if (argv[1 + 1])
				custom_id = argv[pos + 1];
			else
				error_manager(env, INVALID_CHAMPION_ID);
			pos += 2;
		}
		if (env.nb_of_champions < MAX_PLAYERS)
			parse_champion(&env, custom_id, argv[pos]);
		else
			error_manager(env, TOO_MANY_CHAMPIONS);
		pos++;
	}
	if (env.nb_of_champions == 0)
		error_manager(env, NO_CHAMPIONS);
	return (env);
}
