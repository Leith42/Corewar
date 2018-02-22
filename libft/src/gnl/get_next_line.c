/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:29:29 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/25 19:38:25 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_gnl_lstadd(t_file **alst, t_file *new)
{
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

static void		ft_gnl_realloc(t_file *f, int n)
{
	char *tmp;

	f->pos += n;
	f->save[f->pos] = '\0';
	if (!n)
		return ;
	tmp = (char *)malloc(sizeof(char) * (f->pos + BUFF_SIZE + 1));
	ft_strcpy(tmp, f->save);
	free(f->save);
	f->save = tmp;
}

static t_file	*ft_init(int fd, t_file **files)
{
	t_file	*tmp;
	int		n;

	tmp = *files;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(tmp->save = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(tmp);
		return (NULL);
	}
	tmp->fd = fd;
	tmp->pos = 0;
	while ((n = read(fd, &tmp->save[tmp->pos], BUFF_SIZE)) > 0)
		ft_gnl_realloc(tmp, n);
	tmp->pos = 0;
	tmp->next = NULL;
	ft_gnl_lstadd(files, tmp);
	return ((n < 0) ? NULL : tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files = NULL;
	t_file			*f;
	size_t			n;

	n = 0;
	if (!(line) || (fd < 0) || !(f = ft_init(fd, &files)))
		return (-1);
	while ((f->save[f->pos] != '\n') && (f->save[f->pos] != '\0'))
	{
		f->pos++;
		n++;
	}
	*line = ft_strsub(f->save, (unsigned int)f->pos - n, n);
	if (f->save[f->pos] == '\0')
		return ((n) ? 1 : 0);
	if (f->save[f->pos++] == '\n')
		return (1);
	return (-1);
}
