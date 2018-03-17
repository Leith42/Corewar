/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:47:11 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/17 01:00:06 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

void	add_new_process(t_env *env, unsigned int champion_id)
{
	t_process	*process;
	t_list		*tmp;
	size_t		i;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		ft_free_exit(*env, NULL, 1, 0);
	process->reg[0] = champion_id;
	i = 1;
	while (i < REG_NUMBER)
		process->reg[i++] = 0;
	process->champ_id = champion_id;
	process->cycle_to_wait = 0;
	process->cur_opcode = 0;
	process->aff_buffer = NULL;
	if (!(tmp = ft_lstnew((void *)process, sizeof(t_process))))
		ft_free_exit(*env, NULL, 1, 0);
	ft_lstpush_front(&(env->process), tmp);
}

size_t	kill_dead_process(t_env *env)
{
	size_t	nb_death;
	t_list	**prev_next;
	t_list	*cur;

	nb_death = 0;
	prev_next = &env->process;
	cur = env->process;
	while (cur)
	{
		if (((t_process *)(cur->content))->is_alive == false)
		{
			*prev_next = cur->next;
			if (((t_process *)(cur->content))->aff_buffer != NULL)
				free(((t_process *)(cur->content))->aff_buffer);
			free(cur->content);
			free(cur);
			nb_death++;
			cur = *prev_next;
			continue;
		}
		((t_process *)(cur->content))->is_alive = false;
		prev_next = &(cur->next);
		cur = cur->next;
	}
	return (nb_death);
}
