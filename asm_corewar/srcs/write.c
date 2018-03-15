/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:03 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/08 10:04:26 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		ft_putchar_fd(magic_tab[i], fd);
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

int		ft_write(char *file_name, unsigned char *tab, t_header *header)
{
	//int fd;
	char *new_file_name;

	(void)tab;
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
