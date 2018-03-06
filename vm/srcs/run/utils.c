/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 11:42:09 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Displays current arena state in lines of line_len bytes in hex format.
*/

void	disp_arena(t_env *env, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02X ", env->arena[i]);
		i++;
		if ((i % line_len) == 0)
			ft_putchar('\n');
	}
}
