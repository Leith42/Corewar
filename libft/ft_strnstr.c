/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:29:18 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/16 22:45:03 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		l;
	size_t	i;

	l = 0;
	i = 0;
	if (!little[i])
		return (char *)(big);
	while (big[i] && i < len)
	{
		if (big[i] == little[l])
		{
			while (big[i + l] == little[l] && big[i + l] && i + l < len)
				l++;
			if (!little[l])
				return (char *)(&big[i]);
			l = 0;
		}
		i++;
	}
	return (0);
}
