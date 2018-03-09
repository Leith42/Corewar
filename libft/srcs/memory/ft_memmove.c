/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 06:47:25 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:55:43 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	int				dir;

	dir = (dst < src) ? 1 : -1;
	i = (dir == 1) ? 1 : n;
	while ((dir == 1 && i < n + 1) || i > 0)
	{
		*((unsigned char *)dst + i - 1) = *((unsigned char *)src + i - 1);
		i += (size_t)dir;
	}
	if (dir == -1 && n != 0)
		*(unsigned char *)dst = *(unsigned char *)src;
	return (dst);
}
