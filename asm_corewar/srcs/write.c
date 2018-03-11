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

int		ft_write(char *file_name, unsigned char *tab)
{
	int n;
	int fd;
	char *new_file_name;

	n = -1;
	new_file_name = ft_strjoin(ft_strndup(file_name, ft_strlen(file_name) - 2), ".cor"); // degueulasse mais c'est l'idée :)
	if ((fd = open(new_file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR)))
	{	
		ft_printf("Fichier %s crée avec succès !\n", new_file_name);
		(void)tab;
		//creation file_name
		/*while (tab[++n])
		{
			//convertir unsigned char en binaire
			//write binaire dans file_name
		}*/
	}
	return (0);
}
