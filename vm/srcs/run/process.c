/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:47:11 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/08 23:52:41 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

size_t	kill_dead_process(t_env *env)
{
	t_list	*lst_cur;
	t_list	*lst_prev;
	t_list	**start;
	size_t	nb_proc_killed;

	nb_proc_killed = 0;
	start = &(env->process);
	lst_prev = env->process;
	lst_cur = env->process;
	while (lst_cur)
	{
		if (!((t_process *)lst_cur->content)->is_alive && nb_proc_killed++)
		{
			if (lst_cur == *start)
				*start = lst_cur->next;
			else
				lst_prev->next = lst_cur->next;
			free(lst_cur);
		}
		else
			((t_process *)lst_cur->content)->is_alive = 0;
		if (!(lst_prev = lst_prev->next))
			break ;
		lst_cur = lst_prev->next;
	}
	return (nb_proc_killed);
}

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
	if (!(tmp = ft_lstnew((void *)process, sizeof(t_process))))
		ft_free_exit(*env, NULL, 1, 0);
	ft_lstpush_front(&(env->process), tmp);
}
