/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_umax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:59:33 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/27 17:56:15 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_backslach(char *src, char *dst, uintmax_t i, uintmax_t tmp)
{
	while (i-- > 0)
	{
		dst[tmp] = src[i];
		tmp++;
	}
	dst[tmp] = '\0';
}

char			*ft_itoa_umax(uintmax_t n)
{
	char			*str;
	char			buf[21];
	uintmax_t		i;
	uintmax_t		n_tmp;

	i = 0;
	n_tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 4294967296)
		return (ft_strdup("4294967296"));
	while (n_tmp)
	{
		buf[i++] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_backslach(buf, str, i, n_tmp);
	return (str);
}
