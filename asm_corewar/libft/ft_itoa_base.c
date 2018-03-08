/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:11:49 by mmatime           #+#    #+#             */
/*   Updated: 2017/11/04 19:12:46 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nb_len(int value, int base)
{
	int i;

	i = 0;
	if (!value || (value < 0 && base == 10))
		i = 1;
	while (value)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*str;

	i = nb_len(value, base);
	str = malloc((sizeof(char) * i) + 1);
	str[i] = 0;
	i--;
	if (base == 10 && value < 0)
		str[0] = '-';
	if (value > 0)
		value = -value;
	if (!value)
		str[i] = '0';
	while (value)
	{
		str[i] = -(value & base) + '0';
		if (-(value % base) >= 10 && base > 10)
			str[i] += 7;
		value = value / base;
		i--;
	}
	return (str);
}
