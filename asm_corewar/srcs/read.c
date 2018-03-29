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
	t_lst_op		*lst; //liste des instructions
	int				lnbr;
	int				n;
	t_header		header;

	lnbr = 0;
	n = 0;
	(void)file_name;
	//printf("file_name = %s\n", file_name);
	lst = init_lst();
	if ((lnbr = check_header(fd, &header)) != 0 && check_inst(lst, fd, lnbr))
		;//ft_write(file_name, lst, &header);
	else
		return (0);
	//print_inst(1, lst);
	return (1);
}
