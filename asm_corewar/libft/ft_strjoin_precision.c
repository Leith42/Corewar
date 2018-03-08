/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:13:39 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/19 14:17:08 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_precision(char const *s1, char const *s2, int len)
{
	int		i;
	int		j;
	int		a;
	char	*str;

	i = 0;
	j = 0;
	a = 0;
	if (!s1)
		s1 = ft_strnew(1);
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(char) * ((i + len) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[a++] = s1[i++];
	while (j < len)
		str[a++] = s2[j++];
	str[a] = '\0';
	return (str);
}
