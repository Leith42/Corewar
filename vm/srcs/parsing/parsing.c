/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:54:24 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/05 19:03:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Ensure that the dump cycle is a positive integer and returns it.
**	Todo: fix overflow, atoi is crap.
*/

static size_t	get_dump_cycle(char **argv, size_t *pos, t_env env)
{
	int	cycles;

	if (env.dump_cycle)
		error_manager(env, NB_OF_CYCLES_ALREADY_EXISTS);
	if (argv[*pos + 1] == NULL || is_string_numeric(argv[*pos + 1]) == false)
		error_manager(env, INVALID_NB_OF_CYCLES);
	cycles = ft_atoi(argv[*pos + 1]);
	*pos += 2;
	return ((size_t)cycles);
}

/*
**	Starting point of the parsing.
**	Here we make sure that all arguments are valid.
**	Generates and return the main structure of Corewar (t_env).
**	Todo: must be factorized, the function is disgusting.
*/

void			parse_argv(t_env *env, char **arguments)
{
	size_t		index;
	char		*custom_id;

	index = 0;
	while (arguments[index])
	{
		custom_id = NULL;
		if (ft_strequ(arguments[index], "-dump") == true)
			env->dump_cycle = get_dump_cycle(arguments, &index, *env);
		if (arguments[index] == NULL)
			break ;
		if (ft_strequ(arguments[index], "-n") == true)
		{
			if (arguments[index + 1] == NULL)
				error_manager(*env, INVALID_CHAMPION_ID);
			custom_id = arguments[index + 1];
			index += 2;
		}
		if (env->nb_of_champions >= MAX_PLAYERS)
			error_manager(*env, TOO_MANY_CHAMPIONS);
		parse_champion(env, custom_id, arguments[index]);
		index++;
	}
	if (env->nb_of_champions == 0)
		error_manager(*env, NO_CHAMPIONS);
}
