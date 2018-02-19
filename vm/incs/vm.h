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
	size_t		id;
}				t_champion;

// Todo: Don't know if a structure representing the arena (memory) is relevant, we'll think about it.

typedef struct	s_env
{
	unsigned char	arena[MEM_SIZE + 1];
	t_champion		champion[MAX_PLAYERS + 1];
	t_options		options;
	size_t 			nb_of_champions;
}				t_env;

// Parsing
t_env	parse_argv(char **argv);

// Utils
bool	is_string_numeric(char *s);

// Errors
void	error_manager(enum e_error signal);

#endif
