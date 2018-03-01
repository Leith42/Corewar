/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 07:27:25 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:34:38 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	len = (n < len) ? n : len;
	if (!(dst = ft_strnew(len)))
		return (NULL);
	ft_strncpy(dst, src, len);
	return (dst);
}
