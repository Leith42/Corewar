/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:59:15 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/27 04:06:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

static void		disp_hex_byte(unsigned char byte)
{
	unsigned char	cur;

	cur = byte >> 4;
	if (cur < 10)
		ft_putchar((char)(cur + '0'));
	else
		ft_putchar((char)(cur - 10 + 'a'));
	cur = byte & 15;
	if (cur < 10)
		ft_putchar((char)(cur + '0'));
	else
		ft_putchar((char)(cur - 10 + 'a'));
	ft_putchar(' ');
}

void			dump_memory(t_env *env, size_t line_len)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%#.4x : ", i);
		j = 0;
		while (j < line_len)
			disp_hex_byte(env->arena[i + j++]);
		ft_putchar('\n');
		i += j;
	}
}

void			ft_pause(t_env *env)
{
	ssize_t	ret;
	char	*buf;

	if (!(buf = ft_strnew(1)))
		ft_free_exit(*env, "Malloc error", 1, 0);
	*buf = '\0';
	while (*buf != '\n')
		if ((ret = read(0, buf, 1)) != 1)
			ft_free_exit(*env, "Read error", 1, 0);
}

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