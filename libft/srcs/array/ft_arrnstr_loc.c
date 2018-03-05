/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnstr_loc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:35:33 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 14:36:35 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrnstr_loc(char **arr, char *str, size_t n)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strnequ(arr[i], str, n))
			return (i);
		i++;
	}
	return (-1);
}
