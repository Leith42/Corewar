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
	int				i;
	t_header		header;

	lnbr = 0;
	n = 0;
	printf("file_name = %s\n", file_name);
	lst = init_lst(0);
	printf("lst = %p\n", lst);
	if ((lnbr = check_header(fd, &header)) != 0 && check_inst(lst, fd, lnbr))
		(void)i;//ft_write(File_Name, tab);*/
	else
		return (0);
	return (1);
}
