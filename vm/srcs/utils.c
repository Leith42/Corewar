#include <vm.h>

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