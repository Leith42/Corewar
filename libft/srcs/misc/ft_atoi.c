/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:55:46 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/13 14:46:15 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		n;

	result = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(str[n]))
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		sign = (str[n] == '-') ? -1 : 1;
		n++;
	}
	while (str[n] && ft_isdigit(str[n]))
	{
		result = (result * 10) + (str[n] - '0');
		n++;
	}
	return (sign * result);
}
