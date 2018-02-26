#include <fcntl.h>
#include "vm.h"

//TODO: Ensure that all IDs are unique.
static void	parse_champion_id(t_env *e, char *custom_champion_id, t_champion *new_champion)
{
	int			champion_id;

	if (custom_champion_id)
	{
		if (is_string_numeric(custom_champion_id) == false)
			error_manager(INVALID_CHAMPION_ID);
		champion_id = ft_atoi(custom_champion_id);
		new_champion->id = champion_id;
	}
	else
	{
		if (e->nb_of_champions == 0)
			new_champion->id = 1;
		else
			new_champion->id = e->champions[e->nb_of_champions - 1].id + 1;
	}
	e->nb_of_champions++;
}

static int is_cor_file(char *program_file)
{
	size_t len;

	if (program_file)
	{
		len = ft_strlen(program_file);
		if (len > 4 && ft_strcmp(&program_file[len - 4], ".cor") == 0)
		{
			return (true);
		}
	}
	return (false);
}

static void	parse_champion_program(t_env *e, t_champion *champion, char *program_path)
{
	int	fd;

	if (is_cor_file(program_path) == false)
		error_manager(INVALID_FILE_EXTENSION);
	if ((fd = open(program_path, O_RDONLY)) == ERROR)
		error_manager(OPEN_FILE_FAILED);
	//TODO
}

void		parse_champion(t_env *e, char *custom_id, char *program_path)
{
	t_champion *champion;

	champion = &e->champions[e->nb_of_champions];
	parse_champion_id(e, custom_id, champion);
	parse_champion_program(e, champion, program_path);
}
