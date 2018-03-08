/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:48:10 by mmatime           #+#    #+#             */
/*   Updated: 2018/02/19 17:48:13 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_longtoi(const char *str)
{
	long	i;
	int		negativ;
	long	nb;

	i = 0;
	negativ = 0;
	nb = 0;
	if (str[i] == '-')
	{
		negativ = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		if ((nb > 2147483647 && !negativ) || (nb > 2147483648 && negativ))
			return (0);
		i++;
	}
	return (1);
}
