/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:54:44 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/07 20:49:13 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

static bool	is_id_unique(unsigned int id, t_champion *champions)
{
	size_t	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (id == champions[i].id)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

/*
**	Add or generates an ID (player's number) for the champion.
*/

static void	parse_champion_id(t_env *env, char *custom_champion_id,
		t_champion *current_champion)
{
	unsigned int	champion_id;
	unsigned int	last_champion_id;

	if (custom_champion_id)
	{
		if (is_string_numeric(custom_champion_id) == false)
			error_manager(*env, INVALID_CHAMPION_ID);
		if ((champion_id = ft_unsigned_atoi(custom_champion_id)) == 0)
			error_manager(*env, INVALID_CHAMPION_ID);
		if (is_id_unique(champion_id, env->champions) == false)
			error_manager(*env, CHAMPION_ID_IS_ALREADY_TAKEN);
		current_champion->id = champion_id;
	}
	else
	{
		if (env->nb_of_champions == 0)
			env->champions[env->nb_of_champions].id = 1;
		else
		{
			last_champion_id = env->champions[env->nb_of_champions - 1].id + 1;
			while (is_id_unique(last_champion_id, env->champions) == false)
				last_champion_id++;
			current_champion->id = last_champion_id;
		}
	}
}

/*
**	Simply check if the file extension of the binary is '.cor'.
**	If not, Corewar will stop.
*/

static int	is_cor_file(char *program_path)
{
	size_t filename_length;

	if (program_path)
	{
		filename_length = ft_strlen(program_path);
		if (filename_length > 4
				&& ft_strcmp(&program_path[filename_length - 4], ".cor") == 0)
			return (true);
	}
	return (false);
}

/*
**	The processes are initialized and the IDs of the champions
**  are registered in their r1 (reg[0]).
*/

static void	parse_champion_program(t_env *env, char *program_path,
		unsigned int champion_id)
{
	t_process	*process;
	t_list		*tmp;

	if (is_cor_file(program_path))
	{
		parse_file(env, program_path);
		process = init_process(env, champion_id);
		if (!(tmp = ft_lstnew((void *)process, sizeof(t_process))))
			error_manager(*env, MEMORY_ALLOCATION_FAILED);
		ft_lstpush_front(&(env->process), tmp);
	}
	else
		error_manager(*env, INVALID_FILE_EXTENSION);
}

void		parse_champion(t_env *env, char *custom_id, char *program_path)
{
	t_champion *champion;

	champion = &env->champions[env->nb_of_champions];
	parse_champion_id(env, custom_id, champion);
	parse_champion_program(env, program_path, champion->id);
	env->nb_of_champions++;
}
