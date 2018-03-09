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
	int				n;

	(void)file_name;
	line = NULL;
	if (check_header(fd, line)) //Verification header, mmatime sur le coup
		ft_putendl("HEADER OK");
	else
		return (0);
	while ((n = get_next_line(fd, &line)) != -1)
	{
	//	if (!(check_instruc(line, &tab))) //Verification instruction
			// exit & "erreur instruc"
	//	free (line);
	}
	//ft_write(File_Name, tab);
	return (1);
}