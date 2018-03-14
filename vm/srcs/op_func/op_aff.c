/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:56:37 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/12 22:10:40 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

static void	add_to_buffer(unsigned int param, t_process *process, t_env *env)
{
	unsigned char	*new_buffer;
	unsigned char	reg_value[2];

	reg_value[0] = (unsigned char)param;
	reg_value[1] = '\0';
	new_buffer = (unsigned char *)ft_strjoin(
			(const char *)process->aff_buffer,
			(const char *)reg_value);
	if (new_buffer == NULL)
		ft_free_exit(*env, NULL, 1, 0);
	free(process->aff_buffer);
	process->aff_buffer = new_buffer;
}

int			do_aff(t_process *process, t_env *env)
{
	unsigned int	reg_number;
	unsigned int	reg_value;
	bool			carry;

	reg_number = get_param_raw_value(env, process->pc + 2, T_REG, OP_AFF);
	reg_value = process->reg[reg_number - 1] % 256;
	if (reg_value != '\0')
	{
		add_to_buffer(reg_value, process, env);
		carry = false;
	}
	else
	{
		if (process->aff_buffer != NULL)
		{
			ft_printf("%s\n", process->aff_buffer);
			ft_memdel((void **)&process->aff_buffer);
		}
		carry = true;
	}
	process->pc += 2 + 1;
	return (carry);
}
