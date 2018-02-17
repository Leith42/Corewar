/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:39:20 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/16 22:45:24 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	int		n;

	n = 0;
	if (!s)
		return (NULL);
	if (!(tr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (n < len)
	{
		if (!s[start + n])
			return (NULL);
		tr[n] = s[start + n];
		n++;
	}
	tr[n] = '\0';
	return (tr);
}
