/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:03 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/05 03:24:55 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	print_inst - Ecrit dans le fd la totalité des octets d'instructions
*/

static void	print_inst(int fd, t_lst_op *inst)
{
	int n;

	while (inst)
	{
		n = 0;
		while (n < inst->pos)
			write(fd, &inst->op[n++], 1);
		inst = inst->next;
	}
}

/*
**	print_magic_number - Ecrit dans le fd le magic number
*/

static void	print_magic_number(int fd)
{
	int				i;
	unsigned char	magic_tab[4];
	int				magic_num;

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

/*
**	file_size - Calcule et renvoit le nb d'octet du fichier entier
*/

static int	file_size(t_lst_op *lst)
{
	int champion;

	champion = 0;
	while (lst)
	{
		champion += lst->pos;
		lst = lst->next;
	}
	return (champion);
}

/*
**	print_header - Ecrit dans le fd sous forme d'octet .name, .comment,
**	et la taille du fichier
*/

static void	print_header(int fd, t_header *header, t_lst_op *lst)
{
	int		i;
	int		champion;
	char	champion_size[4];

	i = 0;
	champion = file_size(lst);
	while (i < PROG_NAME_LENGTH)
		write(fd, &header->prog_name[i++], 1);
	write(fd, "\0\0\0\0", 4);
	i = 0;
	while (i < 4)
	{
		champion_size[i] = champion;
		champion >>= 8;
		i++;
	}
	while (--i >= 0)
		write(fd, &champion_size[i], 1);
	i = 0;
	while (i < COMMENT_LENGTH)
		write(fd, &header->comment[i++], 1);
	write(fd, "\0\0\0\0", 4);
}

/*
**	ft_write - Ecrit dans le fd la totalité du fichier
*/

int			ft_write(char *file_name, t_lst_op *lst, t_header *header)
{
	int		fd;
	char	*new_file_name;
	char	*file_name_tmp;

	file_name_tmp = ft_strndup(file_name, ft_strlen(file_name) - 2);
	new_file_name = ft_strjoin(file_name_tmp, ".cor");
	if ((fd = open(new_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0755)))
	{
		ft_printf("Fichier %s crée avec succès !\n", new_file_name);
		print_magic_number(fd);
		print_header(fd, header, lst);
		print_inst(fd, lst);
	}
	free(file_name_tmp);
	free(new_file_name);
	free_lst(lst);
	return (0);
}
