/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:41:04 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/19 14:05:26 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char *s1, char *s2, char c)
{
	if (c == 'E')
		ft_strdel(&s1);
	if (c == 'F')
		ft_strdel(&s2);
	if (c == 'G')
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
}

char			*ft_strjoinfree(char const *s1, char const *s2, char c)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = (char*)malloc(sizeof(dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	ft_free((char*)s1, (char*)s2, c);
	return (dest);
}
