/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:31:09 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/22 03:13:05 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(const char *filename)
{
	char	*res;

	res = ft_strrchr(filename, '/');
	if (res)
		return (res + 1);
	return ((char *)filename);
}
