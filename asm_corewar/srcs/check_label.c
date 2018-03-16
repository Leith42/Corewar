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

/*t_label	*clean_inst(t_label *new, char *src)
{
	if (src[0] == LABEL_CHAR)
		new->name = ft_strndup(src, ft_strlen(src) - 1);
	else
	{
		src++;
		new->name = ft_strdup(src);
	}
	return (new);
}*/

void	set_label_name(t_label *new, char *src)
{
	if (src[0] == DIRECT_CHAR) 
		new->name = ft_strsub(src, 2, ft_strlen(src)); // si str = %:salut
	else
		new->name = ft_strsub(src, 0, ft_strlen(src - 1)); // si str = salut:
}

void	add_to_lst(t_label *label_list, t_label *new)
{
	t_label *tmp;

	tmp = label_list;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		label_list = new;
}

/*void	init_node(t_label *label)
{
	label->name = NULL;
	label->pos = 0;
	label->type = 0;
	label->next = NULL;
}*/

/*int		check_label(char **inst, t_label *label)
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
}*/

int		check_label_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == LABEL_CHAR && str[i - 1] == DIRECT_CHAR)
			return (1);
		i++;
	}
	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}

int		check_label(char **inst, t_label *label_list)
{
	int			i;
	t_label		*new;

	i = 0;
	new = NULL;
	while (inst[i])
	{
		if (check_label_char(inst[i])) 
		{
			if (!(new = ft_memalloc(sizeof(t_label)))) // ft_memalloc permet d'init tout à 0 
				return (0);
			set_label_name(new, inst[i]);
			new->type = i;
			add_to_lst(label_list, new);
		}
		i++;
	}
	return (1);
}