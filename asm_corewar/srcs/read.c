/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:21:13 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/21 21:47:14 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_read_file(int fd, char *file_name)
{
	t_lst_op		*lst;
	t_header		header;

	lst = init_lst(0);
	if ((lst->line_nb += check_header(fd, &header)) != 0 && check_inst(lst, fd) && lst->op[0])
		ft_write(file_name, lst, &header);
	else if (!lst->op[0])
		inst_error(NO_INST, lst->line_nb, "");
	return (1);
}
