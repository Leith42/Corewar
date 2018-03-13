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

int					check_params(char **inst, int opcode)
{
	int		n;
	int		type;

	n = -1;
	while (inst[++n])
	{
		if (g_op_tab[opcode].param_nb <= n)
			return (0);
		if (inst[n][0] == 'r')
			type = T_REG;
		if (inst[n][0] == '%')
			type = T_DIR;
		else
			type = T_IND;
		if (!(type & g_op_tab[opcode].param_type[n]))
			return (0);
	}
	return (1);
}

int					get_inst(char **inst)
{
	int 			n;
	int				i;
	int 			oc;
	unsigned char	op[12];

	i = 0;
	n = (inst[0][ft_strlen(inst[0]) - 1] == ':') ? 1 : 0;
	/*
	** Le cas du label en debut de chaine n'est pas gere
	*/
	while (i <= 16 && (ft_strcmp(g_op_tab[i].name, inst[n]) != 0))
		i++;
	if (i == 16)
		return (0); //Erreur instruct
	op[n++] = i + 1;
	check_params(inst + n, i);
	if (g_op_tab.opc == TRUE)
	{

	}
}

int					check_inst(char *line, unsigned char **tab)
{
	char	*line;
	char	**inst;

	while (get_next_line(fd, &line) > 0, 16)
	{
		if (ft_split_inst(line))
		{
			if (!(get_inst(inst)))
				return (0); //Instruction incorrecte
			ft_free_arr(inst);
		}
		free(line);
	}
	return (1);
}
