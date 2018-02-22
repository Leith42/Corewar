#include "vm.h"

size_t		get_dump_cycle(char **argv, size_t *i)
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

void		parse_champion_id(t_env *env, char *custom_champion_id)
{
	int			champion_id;
	t_champion	*new_champion;

	new_champion = &env->champions[env->nb_of_champions];
	if (custom_champion_id)
	{
		if (is_string_numeric(custom_champion_id) == false)
			error_manager(INVALID_CHAMPION_ID);
		champion_id = ft_atoi(custom_champion_id);
		new_champion->id = champion_id;
	}
	else
	{
		//TODO: Ensure that all IDs are unique.
		if (env->nb_of_champions == 0)
			new_champion->id = 1;
		else
			new_champion->id = env->champions[env->nb_of_champions - 1].id + 1;
	}
	env->nb_of_champions++;
}

//TODO: Parse and store champions programs (or not?).
t_env		parse_argv(char **argv)
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
			custom_id = argv[i + 1];
			i += 2;
		}
		if (env.nb_of_champions < MAX_PLAYERS)
		{
			parse_champion_id(&env, custom_id);
		}
		else
			error_manager(TOO_MANY_CHAMPIONS);
		i++;
	}
	if (env.nb_of_champions == 0)
		error_manager(NO_CHAMPIONS);
	return (env);
}
