#include "vm.h"

void	init_champions(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->champions[i].id = 0;
		env->champions[i].program_file = NULL;
		i++;
	}
}

void	init_env(t_env *env)
{
	env->dump_cycle = 0;
	env->nb_of_champions = 0;
	init_champions(env);
}
