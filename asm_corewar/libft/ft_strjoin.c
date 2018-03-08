/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:36:20 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 17:36:35 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	char	*str;

	i = 0;
	j = 0;
	a = 0;
	if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[a++] = s1[i++];
	while (s2[j])
		str[a++] = s2[j++];
	str[a] = '\0';
	return (str);
}
