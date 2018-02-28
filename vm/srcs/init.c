#include "vm.h"

static void	init_champions(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->champions[i].id = 0;
		i++;
	}
}

void		init_env(t_env *env)
{
	env->dump_cycle = 0;
	env->nb_of_champions = 0;
	env->process = NULL;
	init_champions(env);
	ft_bzero(&(env->arena), sizeof(env->arena));
}
