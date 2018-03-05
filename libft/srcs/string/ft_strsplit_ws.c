/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_ws.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:38:44 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 10:17:24 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					**ft_strsplit_ws(char const *src)
{
	char			**dst;
	unsigned int	i;
	int				ret;

	if (!*src || !(dst = ft_arrnew(ft_str_wordnb((char *)src))))
		return (NULL);
	i = 0;
	while ((ret = get_next_word(dst + i, (char *)src, 0)) == 1)
		i++;
	if (ret == -1)
	{
		ft_free_arr(dst);
		return (NULL);
	}
	return (dst);
}
