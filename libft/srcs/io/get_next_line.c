/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:27:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:06:51 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char	*init(const int fd, char **line, char *buf, unsigned int buff_size)
{
	if (fd < 0 || !line || (!buf && !(buf = ft_strnew(buff_size))))
	{
		ft_strdel(&buf);
		return (NULL);
	}
	if (line && *line)
		ft_strdel(line);
	return (buf);
}

int			get_next_line(const int fd, char **line, unsigned int buff_size)
{
	static char		*buf = NULL;
	char			*end;
	int				ret;

	if (!(buf = init(fd, line, buf, buff_size)))
		return (-1);
	while (!*buf || !(end = ft_strchr(buf, '\n')))
	{
		if (!(end = ft_strextend(buf, buff_size)))
			return (-1);
		ret = (int)read(fd, end + ft_strlen(end), buff_size);
		if (!*(buf = end) && ret < 1)
			return (ret);
		if (ret < 1 && (*line = ft_strdup(buf)))
		{
			ft_strdel(&buf);
			return ((!*line) ? -1 : 1);
		}
	}
	*line = ft_strsub(buf, 0, (size_t)(end - buf));
	end = ft_strdup(end + 1);
	ft_strdel(&buf);
	if (!*line || !(buf = end) || !*buf)
		ft_strdel(&buf);
	return (1);
}
