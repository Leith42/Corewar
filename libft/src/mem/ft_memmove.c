/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:27:39 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/15 22:05:02 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	n;

	if (src <= dst)
	{
		n = len;
		while (n > 0)
		{
			n--;
			((char *)dst)[n] = ((char *)src)[n];
		}
	}
	if (src > dst)
	{
		n = 0;
		while (n < len)
		{
			((char *)dst)[n] = ((char *)src)[n];
			n++;
		}
	}
	return (dst);
}
