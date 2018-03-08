/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:18:49 by mmatime           #+#    #+#             */
/*   Updated: 2017/11/16 17:22:19 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_backslach(char *src, char *dst, int i, int tmp)
{
	while (--i >= 0)
	{
		dst[tmp] = src[i];
		tmp++;
	}
	dst[tmp] = '\0';
	return (dst);
}

char			*ft_itoa(int n)
{
	char	*str;
	char	buf[12];
	int		i;
	int		n_tmp;

	i = 0;
	n_tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
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
