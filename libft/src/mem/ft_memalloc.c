/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:11:12 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/15 19:04:25 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)s);
}
