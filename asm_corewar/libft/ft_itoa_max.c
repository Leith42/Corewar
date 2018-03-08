/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:15:21 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/27 17:55:34 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_backslach(char *src, char *dst, intmax_t i, intmax_t tmp)
{
	while (--i >= 0)
	{
		dst[tmp] = src[i];
		tmp++;
	}
	dst[tmp] = '\0';
}

char			*ft_itoa_max(intmax_t n)
{
	char			*str;
	char			buf[21];
	intmax_t		i;
	intmax_t		n_tmp;

	i = 0;
	n_tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
		n_tmp = -n;
	while (n_tmp)
	{
		buf[i++] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	if (n < 0)
		buf[i++] = '-';
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_backslach(buf, str, i, n_tmp);
	return (str);
}
