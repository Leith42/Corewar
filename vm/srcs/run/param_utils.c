/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 22:14:30 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/10 02:41:08 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
** Returns the parameter type (T_DIR, T_REG or T_IND) from an ocp.
** param_nb goes from 0 to 2.
*/

unsigned int	get_param_type(t_env *env, unsigned int pc,
				unsigned int param_nb)
{
	unsigned int	ocp;
	unsigned int	ref_type;
	unsigned int	ocp_type;

	ref_type = g_op_tab[env->arena[pc] - 1].param_type[param_nb];
	ocp = env->arena[pc + 1];
	ocp_type = (ocp >> (6 - (2 * param_nb))) & 3;
	if (!(ref_type & ocp_type))
		return (0);
	return (ocp_type);
}

/*
** returns a unsigned int from a value stored in 1-4 char.
** needed for reading an int stored in the arena.
*/

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
