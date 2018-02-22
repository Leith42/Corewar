#include "vm.h"

size_t		get_dump_cycle(char *arg)
{
	if (is_string_numeric(arg) == false)
		error_manager(INVALID_NB_OF_CYCLES);
	return ((size_t)ft_atoi(arg));
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
		if (env->nb_of_champions == 0)
			new_champion->id = 1;
		else
			new_champion->id = env->champions[env->nb_of_champions - 1].id + 1;
		//TODO: Ensure that all IDs are unique.
	}
	env->nb_of_champions++;
}

t_env		parse_argv(char **argv)
{
	t_env		env;
	size_t		i;
	char		*custom_id;
	size_t		argv_len;

	init_env(&env);
	argv_len = get_argv_len(argv);
	i = 1;
	while(i < argv_len)
	{
		custom_id = NULL;
		if (ft_strequ(argv[i], "-dump") == true)
			env.options.dump_cycle = get_dump_cycle(argv[++i]);
		else if (ft_strequ(argv[i], "-n") == true)
		{
			custom_id = argv[i + 1];
			i += 2;
		}
		if (env.nb_of_champions < MAX_PLAYERS)
		{
			parse_champion_id(&env, custom_id);
			// TODO: Parse programs (.cor).
		}
		else
			error_manager(INVALID_NB_OF_CHAMPIONS);
		i++;
	}
	return (env);
}
