/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 04:40:21 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 03:26:37 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		a;

	if (!*s2)
		return ((char*)s1);
	a = 0;
	while (s1[a])
	{
		if (s1[a] == *s2 && ft_strequ(s1 + a + 1, s2 + 1))
			return ((char*)&s1[a]);
		a++;
	}
	return (NULL);
}
