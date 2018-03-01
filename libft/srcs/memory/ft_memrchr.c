/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:58:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:55:58 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	n--;
	while (n > 0 && *((unsigned char*)s + n) != (unsigned char)c)
		n--;
	if (n == 0 && *((unsigned char*)s + n) != (unsigned char)c)
		return (NULL);
	return ((void*)((unsigned char*)s + n));
}
