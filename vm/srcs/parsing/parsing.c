/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:54:24 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/08 19:36:19 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Ensure that the dump cycle is a positive integer and returns it.
*/

static size_t	get_dump_cycle(char **argv, size_t *pos, t_env *env)
{
	unsigned int	cycles;

	if (env->is_dump_cycle_specified == true)
		ft_free_exit(*env,
				"[-dump nbr_cycles] has already been specified.", 0, 1);
	if (argv[*pos + 1] == NULL || is_string_numeric(argv[*pos + 1]) == false)
		ft_free_exit(*env, "Invalid number of cycles.", 0, 1);
	cycles = ft_unsigned_atoi(argv[*pos + 1]);
	*pos += 2;
	env->is_dump_cycle_specified = true;
	return (cycles);
}

/*
**	Starting point of the parsing.
**	Here we make sure that all arguments are valid.
**	Generates and return the main structure of Corewar (t_env).
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
			env->dump_cycle = get_dump_cycle(arguments, &index, env);
		if (arguments[index] == NULL)
			break ;
		if (ft_strequ(arguments[index], "-n") == true)
		{
			if ((custom_id = arguments[index + 1]) == NULL)
				ft_free_exit(*env, "Champions numbers must be \
strictly positive integers.", 0, 1);
			index += 2;
		}
		if (env->nb_of_champions >= MAX_PLAYERS)
			ft_free_exit(*env, "Too many champions.", 0, 1);
		parse_champion(env, custom_id, arguments[index]);
		index++;
	}
	if (env->nb_of_champions == 0)
		ft_free_exit(*env, "No champions specified.", 0, 1);
}
