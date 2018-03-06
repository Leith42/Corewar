/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:47:11 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/07 00:08:13 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
** Not sure about the process_are_alive
*/

/*
** call function like this list = lstdelnode(list, node);
*/

t_list	*lstdelnode(t_list *cur, t_list *node)
{
	t_list *next;

	if (cur == NULL)
		return (NULL);
	if (cur == node)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		return (next);
	}
	cur->next = lstdelnode(cur->next, node);
	return (cur);
}

int		process_are_alive(t_env *env)
{
	t_process	*process;

	process = (t_process *)env->process;
	while (process)
	{
		if (!process->is_alive)
			return (0);
		process = (t_process *)env->process->next;
	}
	return (1);
}

void	kill_dead_process(t_env *env)
{
	t_list	*process;
	t_list	*start;

	start = env->process;
	process = env->process;
	while (process)
	{
		if (!((t_process *)process->content)->is_alive)
		{
			start = lstdelnode(start, process);
			process = start;
		}
		else
			process = env->process->next;
	}
}
