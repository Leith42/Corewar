/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 10:36:42 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Displays current arena state in lines of 32 bytes in hex format.
*/

void	disp_arena(t_env *env)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02X ", env->arena[i]);
		i++;
		if ((i % 32) == 0)
			ft_putchar('\n');
	}
}
