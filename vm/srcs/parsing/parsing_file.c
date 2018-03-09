/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:54:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/08 19:28:39 by gudemare         ###   ########.fr       */
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
		ft_free_exit(*env, NULL, 1, 1);
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
		ft_free_exit(*env, NULL, 1, 1);
	header->prog_size = swap_uint32(header->prog_size);
	header->magic = swap_uint32(header->magic);
	if (header->magic != COREWAR_EXEC_MAGIC)
		ft_free_exit(*env,
				"Please make sure the files are Corewar champions.", 0, 1);
	if (header->prog_size > CHAMP_MAX_SIZE)
		ft_free_exit(*env, "A champion's program is too big.", 0, 1);
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
		ft_free_exit(*env, NULL, 1, 0);
	current_champion = &env->champions[env->nb_of_champions];
	read_header(env, program_fd, &current_champion->header);
	read_program(env, program_fd, current_champion);
	if (close(program_fd) == -1)
		ft_free_exit(*env, NULL, 1, 0);
}
