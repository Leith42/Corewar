/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:19:26 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:05:20 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "libft.h"

/*
** Reads an entire file to be put in a string. Be careful.
*/

int		ft_read(char *filename, int fd, char **buf, size_t len)
{
	size_t		read_size;
	int			ret;
	struct stat	file_stat;

	if (!buf || (filename != NULL && (fd = open(filename, O_RDONLY)) == -1))
		return (-1);
	if (*buf)
		ft_strdel(buf);
	if (len == 0 && fstat(fd, &file_stat) != 0)
		return (-1);
	if (len == 0 && !S_ISREG(file_stat.st_mode) && !S_ISFIFO(file_stat.st_mode)
		&& !S_ISSOCK(file_stat.st_mode))
	{
		ft_putendl_fd(
		"Error : Tried to exhaustively read an unending or invalid file.", 2);
		return (-2);
	}
	read_size = (len == 0) ? (size_t)file_stat.st_size : len;
	*buf = ft_strnew(read_size);
	ret = (*buf) ? (int)read(fd, *buf, read_size) : -1;
	if (filename != NULL)
		close(fd);
	return (ret);
}
