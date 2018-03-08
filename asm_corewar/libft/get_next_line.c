/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:43:53 by mmatime           #+#    #+#             */
/*   Updated: 2018/03/02 17:56:11 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(char **all, char **line)
{
	char	*tmp;
	int		n;

	if (*all && ft_strcmp(*all, "") && (tmp = ft_strchr(*all, '\n')))
	{
		n = tmp - *all;
		tmp = ft_strdup(tmp);
		*line = ft_strsub(*all, 0, n);
		ft_strdel(all);
		*all = ft_strdup(tmp + 1);
		ft_strdel(&tmp);
		return (1);
	}
	else if (*all && ft_strcmp(*all, "") && !ft_strchr(*all, '\n'))
	{
		*line = ft_strdup(*all);
		ft_strdel(all);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *all = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (read(fd, &buf, 0) < 0)
		return (-1);
	if (!all && (ret = read(fd, &buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		all = ft_strdup(buf);
		ft_bzero(buf, ret);
	}
	while (all && !ft_strchr(all, '\n') &&
			(ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		all = ft_strjoinfree(all, buf, 'E');
		ft_bzero(buf, ret);
	}
	if (all && ft_line(&all, line) == 1)
		return (1);
	return (0);
}
