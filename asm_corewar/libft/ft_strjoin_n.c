/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:17:48 by mmatime           #+#    #+#             */
/*   Updated: 2017/05/24 18:23:49 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_n(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	char	*str;

	i = 0;
	j = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char *)malloc(sizeof(char) * ((i + j) + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[a++] = s1[i++];
	while (s2[j])
		str[a++] = s2[j++];
	str[a++] = '\n';
	str[a] = '\0';
	return (str);
}
