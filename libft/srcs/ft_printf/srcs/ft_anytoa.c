/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anytoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 04:34:09 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/25 09:38:33 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_magnitude_order(long long n)
{
	size_t	res;

	res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static void			ft_itoa_decompose(long long n, char *dst)
{
	while (n > 0)
	{
		*dst = n % 10 + '0';
		n /= 10;
		dst--;
	}
}

char				*ft_anytoa(long long n)
{
	unsigned int	size;
	int				neg;
	char			*dst;

	if (n == -n)
		return (ft_strdup((n == 0) ? "0" : "-9223372036854775808"));
	size = 1;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	size = ft_magnitude_order(n);
	ft_assert(dst = ft_strnew(size + neg + 1));
	if (neg)
		dst[0] = '-';
	ft_itoa_decompose(n, dst + size + neg - 1);
	dst[size + neg] = '\0';
	return (dst);
}
