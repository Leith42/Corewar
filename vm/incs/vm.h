/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:10:32 by gudemare          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/07 00:00:02 by mgonon           ###   ########.fr       */
=======
/*   Updated: 2018/03/07 16:25:54 by gudemare         ###   ########.fr       */
>>>>>>> 9c52c6ef6f6b5700d134f312eb41b7a7441fc40e
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>

# define DUMP_LINE_LEN	32
# define NORETURN _Noreturn void
# define NULL_ID 0

enum						e_error
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
** add champ_id for the display
** add is_alive
*/
typedef	struct			s_process
{
	unsigned int		pc;
	unsigned int		reg[REG_NUMBER];
	unsigned int		champ_id;
	bool				is_alive;
	bool				carry;
}						t_process;

typedef	struct			s_champion
{
	t_header			header;
	unsigned int		id;
	unsigned char		program[CHAMP_MAX_SIZE];
}						t_champion;

/*
** Todo: Don't know if a structure representing the arena (memory) is relevant,
** we'll think about it.
** add cycle_to_die
** add nb_live;
*/
typedef struct			s_env
{
	unsigned char		arena[MEM_SIZE];
	unsigned int		mask[MEM_SIZE];
	t_champion			champions[MAX_PLAYERS];
	t_list				*process;
	size_t				dump_cycle;
	unsigned short		nb_of_champions;
	size_t				cycle_to_die;
	size_t				nb_live;
	unsigned int		last_live_id;
}						t_env;

/*
** Init & Parsing
*/
void					init_env(t_env *env);
void					parse_argv(t_env *env, char **argv);
void					parse_champion(t_env *env, char *custom_id,
						char *program_path);
void					parse_file(t_env *env, char *program_path);

/*
** Utils
*/
bool					is_string_numeric(char *s);
void					free_env(t_env env);
unsigned int			swap_uint32(unsigned int x);

/*
** Arena runtime
*/
void					run(t_env *env);
/*
** Arena Init
*/
void					load_champions(t_env *env);
/*
** Arena utils
*/
void					disp_arena(t_env *env, size_t line_len);
void					disp_arena_part(t_env *env, char *color,
						size_t start, size_t end);
void					debug_actions(t_process *process, char *action);

/*
** List of actions tht can be performed by the process
*/
void					do_live(t_process *process, t_env *env);
void					do_ld(t_process *process, t_env *env);
void					do_st(t_process *process, t_env *env);
void					do_zjmp(t_process *process, t_env *env);
void					do_ldi(t_process *process, t_env *env);
void					do_add(t_process *process, t_env *env);
void					do_sub(t_process *process, t_env *env);
void					do_and(t_process *process, t_env *env);
void					do_or(t_process *process, t_env *env);
void					do_xor(t_process *process, t_env *env);
void					do_sti(t_process *process, t_env *env);
void					do_fork(t_process *process, t_env *env);
void					do_lld(t_process *process, t_env *env);
void					do_lldi(t_process *process, t_env *env);
void					do_lfork(t_process *process, t_env *env);
void					do_aff(t_process *process, t_env *env);

/*
** Utils for process
*/
t_list					*lstdelnode(t_list *cur, t_list *node);
int						process_are_alive(t_env *env);
void					kill_dead_process(t_env *env);

/*
** Errors
** error_manager() should have attribute _Noreturn, but the Norm doesn't let it
*/
void					error_manager(t_env env, enum e_error signal);

#endif
