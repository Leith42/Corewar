/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:27:15 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 13:30:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpy(char **dst, char **src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (!(dst[i] = ft_strdup(src[i])))
		{
			ft_free_arr(dst);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
