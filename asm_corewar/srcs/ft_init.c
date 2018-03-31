/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:04:23 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/22 10:09:06 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			fill_tab_null(int *tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab[i] = 0;
		i++;
	}
}

void			init_set(t_header *header)
{
	header->name_is_set = 0;
	header->comment_is_set = 0;
	header->head_error = 0;
	memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
	memset(header->comment, 0, COMMENT_LENGTH + 1);
}

t_lst_op		*init_lst(void)
{
	t_lst_op	*new;

	if (!(new = ft_memalloc(sizeof(t_lst_op))))
		return (NULL);
	if (!(new->label_pos = ft_memalloc(sizeof(int) * 4)))
		return (NULL);
	return (new);
}
