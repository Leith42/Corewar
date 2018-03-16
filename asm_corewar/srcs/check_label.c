/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 01:10:03 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/16 01:13:03 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*clean_inst(t_label *new, char *src)
{
	if (src[0] == LABEL_CHAR)
		new->name = ft_strndup(src, ft_strlen(src) - 1);
	else
	{
		src++;
		new->name = ft_strdup(src);
	}
	return (new);
}

void	add_lst(t_label *label, t_label *new)
{
	while (label->next != NULL)
		label = label->next;
	label->next = new;
}

t_label	*create_lab(t_label *label)
{
	if (!(label = malloc(sizeof(t_label*))))
		return (NULL);
	label->name = NULL;
	label->pos = 0;
	label->type = 0;
	label->next = NULL;
	return (label);
}

int		check_label(char **inst, t_label *label)
{
	int			i;
	t_label		*new;

	i = 0;
	new = NULL;
	while (inst[i])
	{
		if (inst[i][0] == LABEL_CHAR || inst[i][ft_strlen(inst[i] - 1)]\
				== LABEL_CHAR)
		{
			if ((new = create_lab(new)) == NULL)
				return (0);
			clean_inst(new, inst[i]);
			new->type = i;
			add_lst(label, new);
		}
		i++;
	}
	return (1);
}
