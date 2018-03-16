/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_check_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:13:00 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/16 01:12:15 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		find_match(t_label *label, char *str)
{
	t_label	*tmp;

	tmp = NULL;
	if ((tmp = create_lab(tmp)) == NULL)
		return (0);
	tmp = label;
	while (tmp->next != NULL)
	{
		if (tmp->type == 0 && ft_strcmp(tmp->name, str) == 0)
		{
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}

int		double_check_label(t_label *label)
{
	t_label	*src;

	src = label;
	while (label->next != NULL)
	{
		if (label->type == 1 && find_match(src, label->name) == 0)
		{
			free(src);
			return (0);
		}
		label = label->next;
	}
	label = src;
	free(src);
	return (1);
}
