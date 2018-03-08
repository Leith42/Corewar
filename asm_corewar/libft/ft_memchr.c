/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:35:32 by mmatime           #+#    #+#             */
/*   Updated: 2016/11/20 00:45:58 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((unsigned char*)&s[i]);
		i++;
	}
	return (NULL);
}
