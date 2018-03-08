/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:50:30 by mmatime           #+#    #+#             */
/*   Updated: 2017/11/16 18:21:35 by mmatime          ###   ########.fr       */
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

char			*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	char			buf[12];
	int				i;
	unsigned int	n_tmp;

	i = 0;
	n_tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
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
