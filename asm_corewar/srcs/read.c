/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:21:13 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/19 00:15:43 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_read_file(int fd, char *file_name)
{
	t_lst_op		*lst; //liste des instructions
	int				lnbr;
	//t_header		header;

	lnbr = 0;
	printf("file_name = %s\n", file_name);
	if (!(lst = malloc(sizeof(t_lst_op))))
		return (0);
	if (/*(lnbr = check_header(fd, &header)) != 0 && */check_inst(lst, fd, lnbr))
		;//ft_write(File_Name, tab);*/
	else
		return (0);
	return (1);
}
