/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:31:38 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 13:34:01 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrextend(char **src, size_t ext)
{
	char	**dst;

	if (!(dst = ft_arrnew(ft_arrlen(src + ext)))
		|| !ft_arrcpy(dst, src))
	{
		ft_free_arr(dst);
		return (NULL);
	}
	ft_free_arr(src);
	return (dst);
}
