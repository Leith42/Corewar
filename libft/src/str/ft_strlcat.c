/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:40:54 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/18 22:46:38 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		tmp;

	tmp = ft_strlen(dst);
	if (size <= tmp)
		return (ft_strlen(src) + size);
	ft_strncat(dst, src, size - tmp - 1);
	return (ft_strlen(src) + tmp);
}
