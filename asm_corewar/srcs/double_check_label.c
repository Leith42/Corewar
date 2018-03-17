/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_check_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:13:00 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/17 03:45:28 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		find_match(t_label *label_list, char *str)
{
	t_label	*tmp;

	tmp = label_list;
	while (tmp)
	{
		if (tmp->type == 0 && ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		double_check_label(t_label *label_list)
{
	t_label	*tmp;

	tmp = label_list;
	while (tmp)
	{
		if (tmp->type == 1 && find_match(tmp, tmp->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
