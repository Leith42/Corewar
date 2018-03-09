/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 01:27:06 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 01:33:56 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arrdup(char **src)
{
	char	**dst;
	size_t	i;

	if (!src || (i = ft_arrlen(src)) == 0
		|| !(dst = ft_arrnew(i)))
		return (NULL);
	while (--i > 0)
	{
		if (!(dst[i] = ft_strdup(src[i])))
		{
			ft_free_arr(dst);
			return (NULL);
		}
	}
	if (!(dst[0] = ft_strdup(src[0])))
	{
		ft_free_arr(dst);
		return (NULL);
	}
	return (dst);
}
