/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:49:53 by mmatime           #+#    #+#             */
/*   Updated: 2016/11/19 23:22:14 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		buf;
	int		new;
	char	*dest;

	i = 0;
	buf = 0;
	new = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	buf = i;
	while (s[i])
		i++;
	while ((s[i - 1] == ' ') || (s[i - 1] == '\t') || (s[i - 1] == '\n'))
		i--;
	if (!(dest = (char *)malloc(sizeof(char) * ((i - buf) + 1))))
		return (NULL);
	while (s[buf] && buf < i)
		dest[new++] = s[buf++];
	dest[new] = '\0';
	return (dest);
}
