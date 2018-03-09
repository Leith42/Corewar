/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 05:54:34 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/22 04:50:37 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		offset;
	size_t		i;

	offset = 0;
	i = 0;
	while (dst[offset] && offset < n)
		offset++;
	if (!dst[offset])
	{
		while (src[i] && offset + i < n - 1)
		{
			dst[offset + i] = src[i];
			i++;
		}
		dst[offset + i] = '\0';
	}
	return (offset + (size_t)ft_strlen(src));
}
