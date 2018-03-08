/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:22:49 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/05 17:04:52 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

unsigned int	ft_unsigned_atoi(const char *str)
{
	unsigned int		result;
	unsigned int		sign;
	unsigned int		n;

	result = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(str[n]))
		n++;
	while (str[n] && ft_isdigit(str[n]))
	{
		result = (result * 10) + (str[n] - '0');
		n++;
	}
	return (sign * result);
}


bool			is_string_numeric(char *string)
{
	size_t i;

	if (!string)
		return (false);
	i = 0;
	while (string[i] != '\0')
	{
		if (ft_isdigit((int)string[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

unsigned int	swap_uint32(unsigned int x)
{
	return (((x) >> 24) | (((x) & 0x00FF0000) >> 8)
			| (((x) & 0x0000FF00) << 8) | ((x) << 24));
}
