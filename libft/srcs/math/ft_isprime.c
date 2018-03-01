/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:21:58 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/13 16:31:16 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(unsigned int nb)
{
	unsigned int	i;
	unsigned int	lim;

	if (nb < 2)
		return (0);
	i = 2;
	lim = ft_sqrt(nb);
	while (i <= lim)
		if (nb % i++ == 0)
			return (0);
	return (1);
}
