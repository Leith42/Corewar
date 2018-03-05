/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr_loc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 07:29:53 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 07:30:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrstr_loc(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_strequ(arr[i], str))
			return (i);
		i++;
	}
	return (-1);
}
