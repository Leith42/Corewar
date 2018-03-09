/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 04:37:54 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 03:21:29 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dst;

	if (!(dst = ft_strnew(ft_strlen(src))))
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}
