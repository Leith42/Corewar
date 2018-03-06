/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:54:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 10:48:59 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "vm.h"
#include <fcntl.h>

/*
**	Read the instructions of a champion's program.
*/

static void	read_program(t_env *env, int program_fd,
		t_champion *current_champion)
{
	if (read(program_fd, current_champion->program, CHAMP_MAX_SIZE) == -1)
		error_manager(*env, READ_FILE_FAILED);
}

/*
**	Read the header of a champion's program.
**	Convert numbers from little to big-endian (321 become 123).
**	Make sure the file is a Corewar champion by checking its magic number.
**	Also check that the program is not bigger (in bytes) than CHAMP_MAX_SIZE.
*/

static void	read_header(t_env *env, int program_fd, t_header *header)
{
	if (read(program_fd, header, sizeof(t_header)) != sizeof(t_header))
		error_manager(*env, READ_FILE_FAILED);
	header->prog_size = swap_uint32(header->prog_size);
	header->magic = swap_uint32(header->magic);
	if (header->magic != COREWAR_EXEC_MAGIC)
		error_manager(*env, NOT_A_CHAMPION_FILE);
	if (header->prog_size > CHAMP_MAX_SIZE)
		error_manager(*env, FILE_IS_TOO_BIG);
}

/*
**	Open, read and check that the program is well formated.
**	If not, Corewar will stop.
*/

void		parse_file(t_env *env, char *program_path)
{
	int			program_fd;
	t_champion	*current_champion;

	if ((program_fd = open(program_path, O_RDONLY)) == -1)
		error_manager(*env, OPEN_FILE_FAILED);
	current_champion = &env->champions[env->nb_of_champions];
	read_header(env, program_fd, &current_champion->header);
	read_program(env, program_fd, current_champion);
	if (close(program_fd) == -1)
	{
		error_manager(*env, CLOSE_FILE_FAILED);
	}
}
