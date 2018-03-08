/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:10:32 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/08 21:45:21 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>

# define DUMP_LINE_LEN	32
# define NULL_ID 0
# define COLOR_P1 "\x1b[31m"
# define COLOR_P2 "\x1b[32m"
# define COLOR_P3 "\x1b[33m"
# define COLOR_P4 "\x1b[34m"

enum					e_error
{
	INVALID_NB_OF_CYCLES,
	NB_OF_CYCLES_ALREADY_EXISTS,
	TOO_MANY_CHAMPIONS,
	NO_CHAMPIONS,
	INVALID_CHAMPION_ID,
	CHAMPION_ID_IS_ALREADY_TAKEN,
	OPEN_FILE_FAILED,
	CLOSE_FILE_FAILED,
	READ_FILE_FAILED,
	INVALID_FILE_EXTENSION,
	MEMORY_ALLOCATION_FAILED,
	NOT_A_CHAMPION_FILE,
	FILE_IS_TOO_BIG,
};

enum					e_opcode
{
	OP_ADD = 0x04,
	OP_AFF = 0x10,
	OP_AND = 0x06,
	OP_FORK = 0x0C,
	OP_LD = 0x02,
	OP_LDI = 0x0A,
	OP_LFORK = 0x0F,
	OP_LIVE = 0x01,
	OP_LLD = 0x0D,
	OP_LLDI = 0x0E,
	OP_OR = 0x07,
	OP_ST = 0x03,
	OP_STI = 0x0B,
	OP_SUB = 0x05,
	OP_XOR = 0x08,
	OP_ZJMP = 0x09,

};

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

typedef struct			s_env
{
	unsigned char		arena[MEM_SIZE];
	unsigned int		mask[MEM_SIZE];
	t_champion			champions[MAX_PLAYERS];
	t_list				*process;
	unsigned short		nb_of_champions;
	bool				is_dump_cycle_specified;
	size_t				dump_cycle;
	size_t				cycle_to_die;
	size_t				nb_live;
	unsigned int		last_live_id;
	void				(*op_tab[16]) (t_process *process, struct s_env *env);
}						t_env;

typedef struct			s_op
{
	char				*name;
	unsigned short		param_nb;
	unsigned short		param_type[3];
	unsigned short		opcode;
	unsigned short		cycle_nb;
	char				*description;
	bool				ocp;
	bool				addr_or_nb;
}						t_op;

extern t_op				g_op_tab[17];

/*
** Init & Parsing
*/
void					init_env(t_env *env);
t_process				*init_process(t_env *env, unsigned int champion_id);
void					parse_argv(t_env *env, char **argv);
void					parse_champion(t_env *env, char *custom_id,
						char *program_path);
void					parse_file(t_env *env, char *program_path);

/*
** Utils
*/
bool					is_string_numeric(char *s);
void					free_env(t_env env);
void					ft_free_exit(t_env env, char *error,
						bool disp_errno, bool disp_usage);
unsigned int			swap_uint32(unsigned int x);
unsigned int			ft_unsigned_atoi(const char *str);
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
size_t					kill_dead_process(t_env *env);

#endif
