#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include <stdbool.h>

typedef struct	s_options
{
	size_t				dump_cycle;
	unsigned short 		champions_amount;
}				t_options;

typedef	struct 	s_champion
{
	size_t		id;
}				t_champion;

// Todo: Don't know if a structure representing the arena is relevant, we'll think about it.

typedef struct	s_env
{
	unsigned char	arena[MEM_SIZE];
	t_champion		champion[MAX_PLAYERS];
	t_options		options;
}				t_env;

t_env	parse_argv(char **argv);

#endif
