/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:20:09 by mmatime           #+#    #+#             */
/*   Updated: 2017/05/24 18:29:37 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_mod(const char *s1, int size, char c)
{
	int		i;
	int		a;
	char	*dst;

	i = 0;
	a = 0;
	while (s1[i] && a < size)
	{
		if (s1[i] == c)
			a++;
		i++;
	}
	dst = malloc(sizeof(char *) * (i + 1));
	a = i;
	i = 0;
	while (s1[i] && i < a)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
