/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:04:21 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/21 08:07:42 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *s1, const char *s2)
{
	int		a;
	int		b;

	if (!*s2)
		return ((char*)s1);
	a = 0;
	while (s1[a])
	{
		if (ft_toupper((int)s1[a]) == ft_toupper((int)s2[0]))
		{
			b = 1;
			while (s2[b]
				&& ft_toupper((int)s1[a + b]) == ft_toupper((int)s2[b]))
				b++;
			if (!s2[b])
				return ((char*)&s1[a]);
		}
		a++;
	}
	return (NULL);
}
