/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 06:49:29 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/15 08:31:39 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// un brouillon que je mettrais au propre. 

void	ft_add_lst(t_label **label, t_label *new)
{
	while (label->next != NULL)
		label = label->next;
	label->next = new;
}

int		ft_create_lab(t_label *label)
{
	if (!(label = malloc(sizeof(t_label*))))
		return (0);
	label->name = NULL;
	label->pos = 0;
	label->type = 0;
	label->next = NULL;
	return (1);
}

int		ft_check_label(char **inst, t_label *label)
{
	int			i;
	t_label		*new;

	if (inst[0][0] == LABEL_CHAR || inst[0][ft_strlen(inst[0] - 1)] == LABEL_CHAR)
	{
		if (!ft_create_lab(new))
			return (0);
		new->name = ft_strdup(inst[0]);
		new->type = 0; //don't forget to add the location index later.
		ft_add_lst(*label, new);
	}
	i = 1;
	while (inst[i])
	{
		if (inst[i][0] == LABEL_CHAR || inst[i][ft_strlen(inst[i] - 1)] == LABEL_CHAR)
		{
			if (!ft_create_lab(new))
				return (0);
			new->name = ft_strdup(inst[i]);
			new->type = 1;
			ft_add_lst(*label, new);
		}
		i++;
	}
	return (1);
}

int		ft_find_match(t_label *label, char *str)
{
	while (label->next != NULL)
	{
		if (label->type == 0 && ft_strcmp(str, label->name) == 0)
			return (1);
		label = label->next;
	}
	return (0);
}

void	ft_double_check_label(t_label *label)
{
	int		n;

	n = 0;
	while (label->next != NULL)
	{
		if (label->type == 1 && ft_find_match(*label, label->name) == 0)
			return (-1);
		label = label->next;
	}
	return (0);
}
