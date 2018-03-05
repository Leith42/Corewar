/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:23:29 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:03:14 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t			ft_count_words(char const *s, char c)
{
	size_t	word_nb;

	word_nb = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word_nb++;
		while (*s && *s != c)
			s++;
	}
	return (word_nb);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**dst;
	size_t			wordlen;
	unsigned int	index;

	if (!*s || !(dst = ft_arrnew(ft_count_words(s, c))))
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		if ((wordlen = ft_strchr_loc(s, (int)c)) == (size_t)-1)
			wordlen = ft_strlen(s);
		if (!(dst[index++] = ft_strsub(s, 0, wordlen)))
		{
			ft_free_arr(dst);
			return (NULL);
		}
		s += wordlen;
	}
	return (dst);
}
