/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 03:32:20 by gudemare          #+#    #+#             */
/*   Updated: 2018/04/09 22:54:07 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_lst(t_lst_op *lst)
{
	t_lst_op *next;

	next = NULL;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	lst = NULL;
}

void	free_label(t_label *label)
{
	t_label *next;

	next = NULL;
	while (label)
	{
		next = label->next;
		free(label->name);
		free(label);
		label = next;
	}
	label = NULL;
}

int		free_all(t_label *lab, char **inst, t_lst_op *lst, char *l)
{
	free_lst(lst);
	free_label(lab);
	ft_free_arr(inst);
	if (l)
		free(l);
	return (0);
}
