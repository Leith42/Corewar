#include <vm.h>

size_t 	get_argv_len(char **argv)
{
	size_t	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			i++;
		}
	}
	return (i);
}

bool	is_string_numeric(char *s)
{
	size_t i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (ft_isdigit((int) s[i]) == false)
			{
				return (false);
			}
			i++;
		}
		return (true);
	}
	return (false);
}