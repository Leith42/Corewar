/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:59:52 by exam              #+#    #+#             */
/*   Updated: 2016/11/18 22:44:45 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*r;
	int		tmp;
	size_t	size;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	tmp = n;
	size = 2 + (n < 0);
	while ((n = n / 10))
		size++;
	n = tmp;
	if (!(r = (char *)malloc(sizeof(char) * size--)))
		return (0);
	r[size--] = '\0';
	r[size--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		r[size--] = sign * (n % 10) + '0';
	if (sign < 0)
		r[size] = '-';
	return (r);
}
