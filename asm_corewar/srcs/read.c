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
	//unsigned char	*tab; // Definir comment attribuer une size pour tab
//	t_header		header;
	t_lst_op		*lst; //liste des instructions
	t_header		header;

	printf("file_name = %s\n", file_name);
	if (!(lst = malloc(sizeof(t_lst_op))))
		return (0);
	if (check_header(fd, &header) && check_inst(lst, fd)) //Verification header, mmatime sur le coup
		;//ft_write(File_Name, tab);*/
	else
		return (0);
	return (1);
}
