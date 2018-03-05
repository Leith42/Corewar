/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:03:07 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:09:32 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_ten_power(size_t power)
{
	unsigned int	res;

	res = 1;
	while (power-- > 0)
		res *= 10;
	return (res);
}

static void			ft_itoa_decompose(int n, char *dst)
{
	if (n == 0)
		*dst = '0';
	while (n > 0)
	{
		*dst = n % 10 + '0';
		n /= 10;
		dst--;
	}
}

char				*ft_itoa(int n)
{
	size_t	size;
	int		neg;
	char	*dst;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = 1;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while ((unsigned int)n / ft_ten_power(size) > 0 && size < 10)
		size++;
	if (!(dst = ft_strnew(size + (size_t)neg)))
		return (NULL);
	if (neg)
		dst[0] = '-';
	ft_itoa_decompose(n, dst + size + neg - 1);
	dst[size + (size_t)neg] = '\0';
	return (dst);
}
