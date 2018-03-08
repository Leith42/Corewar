/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:47:11 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/08 19:23:29 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

/*
** Not sure about the process_are_alive
*/

/*
** call function like this list = lstdelnode(list, node);
** NOT USING IT ANYMORE. DELETE?
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

size_t	kill_dead_process(t_env *env)
{
	t_list	*lst_cur;
	t_list	*lst_prev;
	t_list	**start;
	size_t	nb_process_killed;

	nb_process_killed = 0;
	start = &(env->process);
	lst_prev = env->process;
	lst_cur = env->process;
	while (lst_cur)
	{
		if (!((t_process *)lst_cur->content)->is_alive)
		{
			if (lst_cur == *start)
				*start = lst_cur->next;
			else
				lst_prev->next = lst_cur->next;
			free(lst_cur);
			nb_process_killed++;
		}
		lst_prev = lst_cur;
		lst_cur = lst_cur->next;
	}
	return (nb_process_killed);
}
