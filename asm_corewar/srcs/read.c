/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:21:13 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/06 15:21:15 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					check_header(int fd)
{
	//lecture des trois premiere lignes, Verification .name et .comment
}

int					check_instruc(char *line, unsigned char **tab)
{
	static int n = -1; //Pour toujours ecrire à la suite
	//enregistrer eventuel label ?
	//verification instruction -> determiner l'opcode
	//verification argument (et definition de l'octet de codage)
	//enregistrement de la commande dans tab
}

int					ft_read(int fd, char *File_Name)
{
	unsigned char	*tab; // Definir comment attribuer une size pour tab
	char			*line;
	int				n;

	if (!(check_header(fd))) //Verification header
		// exit & "erreur header"
	while ((n = get_next_line(fd, &line)) != -1)
	{
		if (!(check_instruc(line, &tab))) //Verification instruction
			// exit & "erreur instruc"
		free (line);
	}
	ft_write(File_Name, tab);
	return (1);
}
