/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:54:16 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/09 16:54:18 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_inst(char **inst)
{
	int n;
	unsigned char 

	n = 0;
	while (inst[++n])
	{
		if (inst[n][0] == '#') //Commentaire
			n++;
		if (inst[n][ft_strlen(inst[n]) - 1] == ':') //Label en debut de chaine
		 	n++;
	}
}

int			check_inst(char *line, unsigned char **tab)
{
	char	*line;
	char	**inst;

	while (get_next_line(fd, &line) > 0)
	{
		if (split(line)) //Split en fonction des espaces, tab et ','
		{
			if (!(get_inst(inst)))
				return (0); //Instruction incorrecte
			free_tab(inst); //Clean double tab
		}
		free(line);
	}
	return (1);
}