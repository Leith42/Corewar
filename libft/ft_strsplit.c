/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:44:59 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/18 22:50:53 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_m(char const *s, char c)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (s[n] == c)
		n++;
	while (s[n])
	{
		m++;
		while (s[n] != c && s[n])
			n++;
		while (s[n] == c)
			n++;
	}
	return (m);
}

static int		ft_l(char const *s, char c)
{
	int n;

	n = 0;
	while (s[n] != c && s[n])
		n++;
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		m;
	int		l;
	int		cp;

	m = -1;
	l = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (1 + ft_m(s, c)))))
		return (NULL);
	while (s[l] == c)
		l++;
	while (s[l])
	{
		m++;
		split[m] = ft_strsub(s, l, (ft_l(&s[l], c)));
		l += ft_l(&s[l], c);
		while (s[l] == c)
			l++;
	}
	split[++m] = NULL;
	return (split);
}
