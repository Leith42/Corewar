/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:08:05 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/22 19:57:10 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_letters(char const *str, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static	int		count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	if (s[i - 1] == c && count)
		count--;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(*tab) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < (count_words(s, c)))
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(char) * (count_letters(&s[k], c) + 1));
		while (s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
