/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:41:31 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/16 22:44:11 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n;
	unsigned int	i;

	i = 0;
	if (!s || !(*f))
		return (NULL);
	while (s[i])
		i++;
	if (!(n = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		n[i] = (*f)(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
