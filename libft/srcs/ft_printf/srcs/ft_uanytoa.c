/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uanytoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 09:56:04 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/25 09:39:13 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_magnitude_order(unsigned long long n)
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

static void			ft_itoa_decompose(unsigned long long n, char *dst)
{
	while (n > 0)
	{
		*dst = n % 10 + '0';
		n /= 10;
		dst--;
	}
}

char				*ft_uanytoa(unsigned long long n)
{
	unsigned int	size;
	char			*dst;

	if (n == 0)
		return (ft_strdup("0"));
	size = 1;
	size = ft_magnitude_order(n);
	ft_assert(dst = ft_strnew(size + 1));
	ft_itoa_decompose(n, dst + size - 1);
	dst[size] = '\0';
	return (dst);
}
