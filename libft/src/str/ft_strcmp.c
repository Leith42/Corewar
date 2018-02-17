/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:16 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/16 00:02:07 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int n;

	n = 0;
	while (s1[n] && s2[n])
	{
		if (s1[n] != s2[n])
			return ((unsigned char)s1[n] - (unsigned char)s2[n]);
		n++;
	}
	if (!s1[n] || !s2[n])
	{
		if (!s1[n])
			return (-(unsigned char)s2[n]);
		if (!s2[n])
			return ((unsigned char)s1[n]);
	}
	return (0);
}
