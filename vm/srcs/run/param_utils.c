/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 22:14:30 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 17:53:44 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
** Untested and probably buggy, but would so fucking proud if it works.
*/

void			write_uint_to_char(t_env *env, unsigned int start,
				unsigned short size, unsigned int value)
{
	while (size-- > 0)
		env->arena[start++ % MEM_SIZE] =
			(unsigned char)((value >> (8 * size)) % 256);
}

/*
** Gets the raw (in-arena) value of a parameter.
** Is not, and needs not to be, protected from bad input.
*/

unsigned int	get_param_raw_value(t_env *env, unsigned int start,
				unsigned short param_type, unsigned short opcode)
{
	unsigned short param_len;

	if (param_type == T_REG)
		param_len = 1;
	else if (param_type == T_IND)
		param_len = 2;
	else
		param_len = (g_op_tab[opcode - 1].addr_or_nb == true) ? 2 : 4;
	return (get_uintfrom_char(env, start, param_len));
}

/*
** Returns the parameter type (T_DIR, T_REG or T_IND) from an ocp.
** param_nb goes from 0 to 2.
*/

unsigned short	get_param_type(t_env *env, unsigned int pc,
				unsigned short opcode, unsigned int param_nb)
{
	unsigned short	ocp;
	unsigned short	ref_type;
	unsigned short	ocp_type;

	if (opcode != 0)
	{
		ref_type = g_op_tab[opcode - 1].param_type[param_nb];
		if (g_op_tab[opcode - 1].ocp == false)
			return (ref_type);
	}
	else
		ref_type = 0;
	ocp = env->arena[(pc + 1) % MEM_SIZE];
	ocp_type = (ocp >> (6 - (2 * param_nb))) & 3;
	if (opcode != 0 && !(ref_type & ocp_type))
		return (0);
	return (ocp_type);
}

/*
** returns a unsigned int from a value stored in 1-4 char.
** needed for reading an int stored in the arena.
*/

unsigned int	get_uintfrom_char(t_env *env,
				unsigned int start, unsigned short size)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		res = res << 8;
		res += (unsigned int)env->arena[(start + i) % MEM_SIZE];
		i++;
	}
	return (res);
}
