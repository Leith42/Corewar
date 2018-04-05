/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:47:11 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/28 18:34:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
**	Create a process by allocating memory according to
**	whether the list of dead processes is empty or not.
**	This way we reduce unnecessary calls to malloc and free.
*/

static t_process	*create_new_process(t_env *env)
{
	t_process	*process;

	if (env->dead_processes == NULL)
	{
		if ((process = malloc(sizeof(t_process))) == NULL)
			ft_free_exit(*env, NULL, 1, 0);
	}
	else
	{
		process = env->dead_processes->content;
	}
	return (process);
}

/*
**	Destroys a node from the list of dead processes.
*/

void				pop_one_dead_process(t_env *env)
{
	t_list	*to_free;

	if (env->dead_processes != NULL)
	{
		to_free = env->dead_processes;
		env->dead_processes = env->dead_processes->next;
		free(to_free->content);
		free(to_free);
	}
}

/*
**	Add a process to the dead processes list.
*/

static void			kill_process(t_list *current, t_env *env)
{
	if (env->visual)
		release_aff_buffer(current->content);
	current->next = NULL;
	if (env->dead_processes == NULL)
		env->dead_processes = current;
	else
		ft_lstpush_back(env->dead_processes, current);
}

void				add_new_process(t_env *env, unsigned int champion_id)
{
	t_process	*process;
	t_list		*current_node;
	size_t		i;

	current_node = env->dead_processes;
	process = create_new_process(env);
	if (current_node == NULL)
	{
		if (!(current_node = ft_lstnew((void *)process, sizeof(t_process))))
			ft_free_exit(*env, NULL, 1, 0);
	}
	else
		env->dead_processes = env->dead_processes->next;
	i = 1;
	while (i < REG_NUMBER)
		process->reg[i++] = 0;
	process->reg[0] = champion_id;
	process->champ_id = champion_id;
	process->cycle_to_wait = 0;
	process->cur_opcode = 0;
	process->aff_buffer = NULL;
	ft_lstpush_front(&(env->process), current_node);
}

size_t				kill_dead_processes(t_env *env)
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
			kill_process(cur, env);
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
