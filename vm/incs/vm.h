#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>
# include <stdint.h>

enum	e_error {
	INVALID_NB_OF_CYCLES,
	INVALID_NB_OF_CHAMPIONS,
	INVALID_CHAMPION_ID,
};

typedef struct	s_options
{
	size_t		dump_cycle;
	size_t		champions_amount;
}				t_options;

typedef	struct 	s_champion
{
	int			id;
//	char		*program_path;
	FILE		*program;
}				t_champion;

// Todo: Don't know if a structure representing the arena (memory) is relevant, we'll think about it.

typedef struct	s_env
{
	unsigned char	arena[MEM_SIZE + 1];
	t_champion		champions[MAX_PLAYERS + 1];
	t_options		options;
	size_t 			nb_of_champions;
}				t_env;


// Init & Parsing.
void	init_env(t_env *env);
t_env	parse_argv(char **argv);

// Utils
bool	is_string_numeric(char *s);
size_t 	get_argv_len(char **argv);
// Errors
void	error_manager(enum e_error signal);

#endif
