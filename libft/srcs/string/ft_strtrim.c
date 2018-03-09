/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:11:26 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:18:46 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_trimlen(char const *s)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start] &&
		(s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		start++;
	if (!s[start])
		return (0);
	end = ft_strlen(s) + (size_t)-1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return (end - start + 1);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	index;
	char	*dst;

	index = 0;
	len = ft_trimlen(s);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	dst[len] = '\0';
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	while (index < len)
	{
		dst[index] = s[index];
		index++;
	}
	return (dst);
}
