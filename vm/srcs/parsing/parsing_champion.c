/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:54:44 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/05 19:00:21 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Add or generates an ID (player's number) for the champion.
**	Todo: ensure that all ID's are unique. /!\
*/

static void	parse_champion_id(t_env *env, char *custom_champion_id,
		t_champion *new_champion)
{
	int			champion_id;

	if (custom_champion_id)
	{
		if (is_string_numeric(custom_champion_id) == false)
			error_manager(*env, INVALID_CHAMPION_ID);
		champion_id = ft_atoi(custom_champion_id);
		new_champion->id = champion_id;
	}
	else
	{
		if (env->nb_of_champions == 0)
			new_champion->id = 1;
		else
			new_champion->id =
				env->champions[env->nb_of_champions - 1].id + 1;
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
		int champion_id)
{
	t_process	*process;

	if (is_cor_file(program_path))
	{
		parse_file(env, program_path);
		if ((process = ft_memalloc(sizeof(t_process))) == NULL)
			error_manager(*env, MEMORY_ALLOCATION_FAILED);
		ft_bzero(&process->reg, sizeof(process->reg));
		process->reg[0] = champion_id;
		if (env->process)
			process->next = env->process;
		env->process = process;
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
