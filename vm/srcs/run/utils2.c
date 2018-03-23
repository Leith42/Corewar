/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:15 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/23 18:51:33 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char		*get_champ_color(t_env *env, unsigned int id)
{
	if (id == env->champions[0].id)
		return (COLOR_P1);
	else if (env->nb_of_champions > 1 && id == env->champions[1].id)
		return (COLOR_P2);
	else if (env->nb_of_champions > 2 && id == env->champions[2].id)
		return (COLOR_P3);
	else if (env->nb_of_champions > 3 && id == env->champions[3].id)
		return (COLOR_P4);
	ft_free_exit(*env, "Bad ID in process !\n", 0, 0);
	return (NULL);
}

void			disp_process_state(t_env *env, t_process *proc)
{
	size_t		i;

	if (proc->cycle_to_wait != 0)
		ft_printf("\x1b[KLe joueur %s%-4d\x1b[0m dort \
durant \x1b[32m%-4d\x1b[0m cycles au pc \x1b[1;36m%-4d\x1b[0m ",
		get_champ_color(env, proc->champ_id),
		proc->champ_id, proc->cycle_to_wait, proc->pc);
	else
		ft_printf("\x1b[KLe joueur %s%-4d\x1b[0m \
effectue un \x1b[1;32m%-4s (%#-.2hx)\x1b[0m au pc \x1b[1;36m%-4d\x1b[0m ",
		get_champ_color(env, proc->champ_id), proc->champ_id,
		(proc->cur_opcode > 16 || proc->cur_opcode == 0) ?
		"null" : g_op_tab[proc->cur_opcode - 1].name,
		(proc->cur_opcode > 16 || proc->cur_opcode == 0) ?
		0x00 : g_op_tab[proc->cur_opcode - 1].opcode, proc->pc);
	ft_putstr("reg = \x1b[1m{\x1b[0m");
	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("%s%x%s", (proc->reg[i] == 0) ? "\x1b[2m" : "\x1b[0m",
				proc->reg[i], (i == 15) ? "\x1b[0;1m}\x1b[0m" : "\x1b[0m,");
		i++;
	}
	ft_putstr("\n\x1b[K");
}
