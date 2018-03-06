/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:31:07 by mgonon            #+#    #+#             */
/*   Updated: 2018/03/06 19:46:19 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** List of actions that can be performed by the process
*/

void	do_aff(t_process *process, t_env *env)
{
	debug_actions(process, "aff");
	(void)env;
}
