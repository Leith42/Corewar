/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:43:00 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 03:22:51 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (size == 0 || !(dst = (char *)malloc(sizeof(*dst) * (size + 1))))
		return (NULL);
	dst[size] = '\0';
	ft_bzero(dst, size);
	return (dst);
}
