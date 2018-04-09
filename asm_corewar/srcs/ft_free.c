/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 03:32:20 by gudemare          #+#    #+#             */
/*   Updated: 2018/04/05 03:32:24 by gudemare         ###   ########.fr       */
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
}