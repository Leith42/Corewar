#include "vm.h"

size_t		get_dump_cycle(char *arg)
{
	if (is_string_numeric(arg) == false)
		error_manager(INVALID_NB_OF_CYCLES);
	return ((size_t)ft_atoi(arg));
}

void		new_champion(t_env env, char *custom_champion_id)
{
	int		champion_id;

	if (custom_champion_id)
	{
//		TODO: Add a champion with a custom id (-n).
//		if (is_string_numeric(custom_champion_id) == false)
//			error_manager(NULL, INVALID_CHAMPION_ID);
//		champion_id = ft_atoi(custom_champion_id);
	}
}

t_env		parse_argv(char **argv)
{
	t_env		env;
	size_t		i;
	char		*custom_id;

	ft_bzero(&env, sizeof(t_env));
	i = 1;
	while(argv[i] != NULL)
	{
		custom_id = NULL;
		if (ft_strequ(argv[i], "-dump") == true)
			env.options.dump_cycle = get_dump_cycle(argv[++i]);
		else if (ft_strequ(argv[i], "-n") == true) {}
			custom_id = argv[++i];
		if (env.nb_of_champions < MAX_PLAYERS)
			new_champion(env, custom_id);
		else
			error_manager(INVALID_NB_OF_CYCLES);
		i++;
	}
	return (env);
}
