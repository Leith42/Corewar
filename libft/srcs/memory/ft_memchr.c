/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:00:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:54:20 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Searches arbitrary memory for a specific byte.
** Implementation by decreasing n is slower than using a counter.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && *((unsigned char*)s + i) != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void*)((unsigned char*)s + i));
}
