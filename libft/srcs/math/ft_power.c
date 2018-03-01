/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:10:54 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:08:11 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	ft_power(int nb, unsigned int power)
{
	unsigned long long int	res;
	unsigned long long int	tmp;

	res = 1;
	while (power > 0)
	{
		tmp = res * (unsigned long long int)nb;
		if (tmp < res)
			return (0);
		res = tmp;
		power--;
	}
	return (res);
}
