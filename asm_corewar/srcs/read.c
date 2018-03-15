/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:21:13 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/08 03:52:41 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_read_file(int fd, char *file_name)
{
	//unsigned char	*tab; // Definir comment attribuer une size pour tab
	char			*line;
//	t_header		header;
	t_lst_op		*lst; //liste des instructions

	printf("file_name = %s\n", file_name);
	if (!(lst = malloc(sizeof(t_lst_op))))
		return (0);
	line = NULL;
	/*if (check_header(fd, line, &header)) //Verification header, mmatime sur le coup
		ft_write(file_name, tab, &header);
	else
		return (0);*/
	if (!(check_inst(line, lst, fd))) //Verification instruction
		 return (0);
	//ft_write(File_Name, tab);*/
	return (1);
}
