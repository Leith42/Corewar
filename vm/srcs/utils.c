#include <vm.h>

bool	is_string_numeric(char *string)
{
	size_t i;

	if (string)
	{
		i = 0;
		while (string[i] != '\0')
		{
			if (ft_isdigit((int) string[i]) == false)
			{
				return (false);
			}
			i++;
		}
		return (true);
	}
	return (false);
}
