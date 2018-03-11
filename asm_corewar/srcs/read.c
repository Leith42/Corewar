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

char	*epur_str_beginning(char *line) // supprime les espaces en debut de ligne
{
	int i;
	char *dest;

	i = 0;
	dest = NULL;
	while ((line[i] && line[i] == ' ') || (line[i] && line[i] == '\t'))
		i++;
	if (line[i])
		dest = ft_strsub(line, i, ft_strlen(line));
	free(line);
	return (dest);
}

int					ft_read_file(int fd, char *file_name)
{
	//unsigned char	*tab; // Definir comment attribuer une size pour tab
	char			*line;
	//int				n;
	unsigned char *tab = NULL; // tab crée juste pour tester la fonction

	line = NULL;
	if (check_header(fd, line)) //Verification header, mmatime sur le coup
		ft_write(file_name, tab);
	else
		return (0);
	/*while ((n = get_next_line(fd, &line, 100)) != -1)
	{
	//	if (!(check_instruc(line, &tab))) //Verification instruction
			// exit & "erreur instruc"
	//	free (line);
	}
	//ft_write(File_Name, tab);*/

	return (1);
}
