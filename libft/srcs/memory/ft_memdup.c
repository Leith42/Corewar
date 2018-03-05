/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 23:25:07 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 03:06:07 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memdup(void *src, size_t n)
{
	void	*dst;

	if (!(dst = ft_memalloc(n)))
		return (0);
	ft_memcpy(dst, src, n);
	return (dst);
}
