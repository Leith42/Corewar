/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 04:43:17 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/04 04:45:41 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;

	if (!*s2)
		return ((char*)s1);
	a = 0;
	while (s1[a] && a < n)
	{
		if (s1[a] == s2[0])
		{
			b = 1;
			while (s2[b] && s1[a + b] == s2[b] && a + b < n)
				b++;
			if (!s2[b])
				return ((char*)&s1[a]);
		}
		a++;
	}
	return (NULL);
}
