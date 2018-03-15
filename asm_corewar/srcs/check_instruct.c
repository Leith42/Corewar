/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:54:16 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/15 08:32:22 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					param_type(char *param)
{
	if (!param)
		return (0);
	if (param[0] == 'r')
		return (T_REG);
	if (param[0] == '%')
		return (T_DIR);
	return (T_IND);
}

int					check_params(char **inst, int opcode)
{
	int		n;
	int		type;

	n = -1;
	while (inst[++n])
	{
		if (g_op_tab[opcode].param_nb <= n)
			return (0);
		type = param_type(inst[n]);
		if (!(type & g_op_tab[opcode].param_type[n]))
			return (0);
	}
	return (1);
}

unsigned char		get_ocp(char **inst)
{
	int type;
	int i;

	i = 0;
	while (i++ <= 4)
	{

	}
}

int					get_inst(char **inst)
{
	int 			n;
	int				i;
	int 			oc;
	unsigned char	op[12];

	i = 0;
	n = (inst[0][ft_strlen(inst[0]) - 1] == ':') ? 1 : 0;
	ft_check_label(inst, tab);
	/*
	** Le cas du label en debut de chaine n'est pas gere
	*/
	while (i <= 16 && (ft_strcmp(g_op_tab[i].name, inst[n]) != 0))
		i++;
	if (i == 16 || check_params(inst + n, i) == 0)
		return (0); //Erreur instruct
	op[n++] = i + 1;
	if (g_op_tab.opc == TRUE)
	{

	}
}

int					check_inst(char *line, unsigned char **tab)
{
	char	*line;
	char	**inst;
//	t_label	*label;

	while (get_next_line(fd, &line) > 0, 16)
	{
		if (ft_split_inst(line))
		{
//			ft_check_label(inst, label); //stock labels in lists.
			if (!(get_inst(inst)))
				return (0); //Instruction incorrecte
			ft_free_arr(inst);
		}
		free(line);
	}
//	if (ft_double_check_label(label) == -1) //checks label calls for adequate declaration.
//		return (0);
	return (1);
}
