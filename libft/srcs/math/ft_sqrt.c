/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:15:45 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/13 14:21:14 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int	res;

	res = 0;
	while (res * res < nb && res < 46341)
		res++;
	if (res * res == nb)
		return (res);
	return (res - 1);
}
