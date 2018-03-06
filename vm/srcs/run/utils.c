/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/06 18:40:33 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Displays current arena state in lines of line_len bytes in hex format.
*/

void	disp_arena_part(t_env *env, char *color, size_t start, size_t end)
{
	ft_printf("%s", color);
	while (start < end)
	{
		ft_printf("%02X ", env->arena[start++]);
		if ((start % 64) == 0)
			ft_putchar('\n');
	}
	ft_printf("\x1b[0m");
}

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
