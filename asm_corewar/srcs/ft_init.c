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

/*
** init_set - Initialise la structure du header
*/

void			init_set(t_header *header)
{
	header->name_is_set = 0;
	header->comment_is_set = 0;
	header->head_error = 0;
	header->name_length = 0;
	header->comment_length = 0;
	header->waiting_next_line = 0;
	memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
	memset(header->comment, 0, COMMENT_LENGTH + 1);
}

/*
**	init_lst - Initialise un maillon d'instruction
*/

t_lst_op		*init_lst(int ln)
{
	t_lst_op	*new;

	if (!(new = ft_memalloc(sizeof(t_lst_op))))
		return (NULL);
	ft_memset(new->label_pos, 0, 4);
	new->pos = 0;
	new->line_nb = ln;
	return (new);
}
