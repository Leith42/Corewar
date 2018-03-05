/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:10:32 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/05 16:36:28 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

# include "libft.h"
# include "op.h"
# include <stdbool.h>

enum				e_error
{
	INVALID_NB_OF_CYCLES,
	NB_OF_CYCLES_ALREADY_EXISTS,
	TOO_MANY_CHAMPIONS,
	NO_CHAMPIONS,
	INVALID_CHAMPION_ID,
	OPEN_FILE_FAILED,
	CLOSE_FILE_FAILED,
	READ_FILE_FAILED,
	INVALID_FILE_EXTENSION,
	MEMORY_ALLOCATION_FAILED,
	NOT_A_CHAMPION_FILE,
	FILE_IS_TOO_BIG,
};

/*
** Not sure about the type since we need (REG_NUMBER * REG_SIZE) bytes.
*/
typedef	struct			s_process
{
	int					pc;
	int					reg[REG_NUMBER];
	bool				carry;
	struct s_process	*next;
}						t_process;

typedef	struct			s_champion
{
	t_header			header;
	int					id;
	unsigned char		program[CHAMP_MAX_SIZE];
}						t_champion;

/*
** Todo: Don't know if a structure representing the arena (memory) is relevant,
** we'll think about it.
*/
typedef struct			s_env
{
	unsigned char		arena[MEM_SIZE];
	t_champion			champions[MAX_PLAYERS];
	t_process			*process;
	size_t				dump_cycle;
	size_t				nb_of_champions;
}						t_env;

/*
** Init & Parsing
*/
void					init_env(t_env *env);
t_env					parse_argv(t_env *env, char **argv);
void					parse_champion(t_env *env, char *custom_id,
						char *program_path);
void					parse_file(t_env *env, char *program_path);

/*
** Utils
*/
bool					is_string_numeric(char *s);
void					free_env(t_env env);

/*
** Errors
*/
void					error_manager(t_env env, enum e_error signal);

#endif
