/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:47:34 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/27 17:56:46 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_backslach(char *src, char *dst,
		long long int i, long long int tmp)
{
	while (--i >= 0)
	{
		dst[tmp] = src[i];
		tmp++;
	}
	dst[tmp] = '\0';
	return (dst);
}

char			*ft_itoa_plus(long long int n, int plus)
{
	char	*str;
	char	buf[21];
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
	if (n < 0 && plus == 1)
		buf[i++] = '-';
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_backslach(buf, str, i, n_tmp);
	return (str);
}
