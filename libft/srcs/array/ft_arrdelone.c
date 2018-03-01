/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:45:39 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/28 22:41:01 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdelone(char **src, int index)
{
	size_t	len;

	len = ft_arrlen(src);
	ft_strdel(src + index);
	return (ft_arrcollapse(src, len));
}
