/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:04:23 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/20 18:04:37 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_set(t_header *header)
{
	header->name_is_set = 0;
	header->comment_is_set = 0;
	header->head_error = 0;
	memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
	memset(header->comment, 0, COMMENT_LENGTH + 1);
}

int		init_lst(t_lst_op *lst, int nb)
{
	if (!lst || !(lst = malloc(sizeof(t_lst_op))))
		return (0);
	lst->pos = 0;
	lst->line_nb = nb;
	return (1);
}
