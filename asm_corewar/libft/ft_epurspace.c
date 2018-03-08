/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:15:14 by mmatime           #+#    #+#             */
/*   Updated: 2017/05/31 14:44:27 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_loop(char *str, char *dst, int i, int a)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		dst[a++] = str[i++];
	}
	dst[a] = '\0';
	if (dst[a - 1] == ' ' || dst[a - 1] == '\t')
		dst[a - 1] = dst[a];
	return (dst);
}

char			*ft_epurspace(char *str)
{
	int		i;
	int		a;
	char	*dst;

	i = 0;
	a = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i++])
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		a++;
	}
	if (str[i - 1] == ' ' || str[i - 1] == '\t')
		a--;
	dst = malloc(sizeof(*dst) * (a + 1));
	i = 0;
	a = 0;
	ft_loop(str, dst, i, a);
	return (dst);
}
