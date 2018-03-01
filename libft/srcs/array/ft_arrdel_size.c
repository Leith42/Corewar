/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 22:58:34 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/28 23:01:39 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

void	ft_arrdel_size(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		ft_strdel(arr + i++);
	free(arr);
}
