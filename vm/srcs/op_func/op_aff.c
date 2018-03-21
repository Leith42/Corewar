/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:56:37 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/15 21:47:28 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

void		release_aff_buffer(t_process *process)
{
	if (process->aff_buffer != NULL)
	{
		ft_printf("A process (%d) in agony says: %s\n",
					process->reg[0], process->aff_buffer);
		free(process->aff_buffer);
	}
	getchar();
}

static void	add_to_buffer(char param, t_process *process, t_env *env)
{
	char			tmp[2];
	char			*new;

	tmp[0] = param;
	tmp[1] = '\0';
	if (process->aff_buffer != NULL)
	{
		if ((new = ft_strjoin(process->aff_buffer, tmp)) == NULL)
		{
			ft_free_exit(*env, NULL, 1, 0);
		}
		free(process->aff_buffer);
		process->aff_buffer = new;
	}
	else
	{
		if (!(process->aff_buffer = malloc(sizeof(char) * 2)))
		{
			ft_free_exit(*env, NULL, 1, 0);
		}
		process->aff_buffer[0] = tmp[0];
		process->aff_buffer[1] = '\0';
	}
}

static void	print_buffer(t_env *env, t_process *process)
{
	char *champion_name;

	champion_name = get_champ_name(env, process->reg[0]);
	if (champion_name != NULL)
	{
		ft_printf("A process belonging to %s says: %s\n",
					champion_name, process->aff_buffer);
	}
	else
	{
		ft_printf("A process (%d) says: %s\n",
					process->reg[0], process->aff_buffer);
	}
}

int			do_aff(t_process *process, t_env *env)
{
	unsigned int	reg_number;
	unsigned int	reg_value;

	reg_number = get_param_raw_value(env, process->pc + 2, T_REG, OP_AFF);
	if (is_reg(reg_number))
	{
		reg_value = process->reg[reg_number - 1] % 256;
		if (reg_value != '\0')
		{
			if (reg_value >= 32 && reg_value <= 126)
				add_to_buffer((char)reg_value, process, env);
		}
		else
		{
			if (process->aff_buffer != NULL)
			{
				print_buffer(env, process);
				free(process->aff_buffer);
				process->aff_buffer = NULL;
			}
		}
		return ((int)reg_value);
	}
	return (0);
}
