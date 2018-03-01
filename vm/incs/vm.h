#ifndef VM_H
# define VM_H
# define VM_USAGE "Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."

# include "libft.h"
# include "op.h"
# include <stdbool.h>

enum				e_error {
	INVALID_NB_OF_CYCLES,
	TOO_MANY_CHAMPIONS,
	NO_CHAMPIONS,
	INVALID_CHAMPION_ID,
	OPEN_FILE_FAILED,
	INVALID_FILE_EXTENSION,
	MEMORY_ALLOCATION_FAILED,
};

typedef	struct 			s_process
{
	int 				pc;
	int 				reg[REG_NUMBER]; // Not sure about the type since we need (REG_NUMBER * REG_SIZE) bytes.
	bool				carry;
	struct s_process	*next;
}						t_process;

typedef	struct 		s_champion
{
	int				id;
}					t_champion;

// Todo: Don't know if a structure representing the arena (memory) is relevant, we'll think about it.

typedef struct		s_env
{
	unsigned char	arena[MEM_SIZE];
	t_champion		champions[MAX_PLAYERS];
	size_t			dump_cycle;
	size_t 			nb_of_champions;
	t_process		*process;
}					t_env;

// Init & Parsing
void				init_env(t_env *env);
t_env				parse_argv(char **argv);
void				parse_champion(t_env *e, char *custom_id, char *program_path);

// Utils
bool				is_string_numeric(char *s);
void				free_env(t_env env);

// Errors
void				error_manager(t_env e, enum e_error signal);

#endif
