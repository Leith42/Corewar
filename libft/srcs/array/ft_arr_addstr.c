/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_addstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:55:27 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/01 00:02:18 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_addstr(char **src, char *new)
{
	char	**dst;
	size_t	len;

	if (!new)
		return (src);
	len = ft_arrlen(src);
	if (!(dst = ft_arrnew(len + 1)))
		return (NULL);
	if (!(dst = ft_arrcpy(dst, src)))
		return (NULL);
	dst[len] = new;
	dst[len + 1] = NULL;
	ft_free_arr(src);
	return (dst);
}
