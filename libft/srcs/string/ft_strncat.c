/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 05:52:45 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:28:41 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	offset;
	size_t	i;

	i = 0;
	offset = ft_strlen(dst);
	while (src[i] && i < n)
	{
		dst[offset + i] = src[i];
		i++;
	}
	dst[offset + i] = '\0';
	return (dst);
}
