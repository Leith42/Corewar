/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 22:14:30 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/09 22:21:43 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

unsigned int	get_uintfrom_char(unsigned char *start, size_t size)
{
	unsigned int	res;
	unsigned int	i;

	if (size > 4 || size == 0)
	{
		ft_dprintf(2, "Internal error : Bad size !\n");
		exit(EXIT_FAILURE);
	}
	res = 0;
	i = 0;
	while (i < size)
	{
		res = res << 8;
		res += (unsigned int)start[i];
		i++;
	}
	return (res);
}
