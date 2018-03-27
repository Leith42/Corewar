/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:03 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/22 10:02:50 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*void	print_inst(int fd, t_lst_op *inst)
{

}*/

void	print_magic_number(int fd)
{
	int i;
	unsigned char magic_tab[4];
	int magic_num;

	i = 0;
	magic_num = COREWAR_EXEC_MAGIC;
	while (i < 4)
	{
		magic_tab[i] = magic_num;
		magic_num >>= 8;
		i++;
	}
	while (--i >= 0)
		write(fd, &magic_tab[i], 1);
}

void	print_header(int fd, t_header *header)
{
	int i;

	i = 0;
	while (i < PROG_NAME_LENGTH)
		write(fd, &header->prog_name[i++], 1);
	write(fd, "\0", 8);
	i = 0;
	while (i < COMMENT_LENGTH)
		write(fd, &header->comment[i++], 1);
	write(fd, "\0", 4);
}

int		ft_write(char *file_name, t_lst_op *lst, t_header *header)
{
	//int fd;
	char *new_file_name;

	(void)lst;
	if (header)
		write (1, "header exist\n", 13);
	new_file_name = ft_strjoin(ft_strndup(file_name, ft_strlen(file_name) - 2), ".cor"); // degueulasse mais c'est l'idée :)
	/*if ((fd = open(new_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0755)))
	{
		ft_printf("Fichier %s crée avec succès !\n", new_file_name);
		print_magic_number(fd);
		print_header(fd, header);
		//creation file_name
		while (tab[++n])
		{
			//convertir unsigned char en binaire
			//write binaire dans file_name
		}
	}*/
	return (0);
}
