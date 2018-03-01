/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcollapse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:36:01 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/28 23:01:07 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strcpy_valid_len(char **dst, char **src, size_t len_dst)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < len_dst)
	{
		while (!src[j])
			j++;
		if (!(dst[i] = ft_strdup(src[j])))
		{
			ft_free_arr(dst);
			return (NULL);
		}
		i++;
		j++;
	}
	return (dst);
}

char		**ft_arrcollapse(char **src, size_t init_len)
{
	size_t	i;
	size_t	len;
	char	**dst;

	i = 0;
	len = 0;
	while (i < init_len)
		if (src[i++] != NULL)
			len++;
	if (len == init_len || len == 0)
	{
		ft_free_arr((len == 0) ? src : NULL);
		return ((len == 0) ? NULL : src);
	}
	if (!(dst = ft_arrnew(len))
		|| !(dst = ft_strcpy_valid_len(dst, src, len)))
		return (NULL);
	ft_arrdel_size(src, init_len);
	return (dst);
}
