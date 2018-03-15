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

int					get_params(char	**inst, unsigned char **op, int opc, int n)
{
	int		dir_size;
	int		i;
	int		type;
	int		nb;

	i = -1;
	dir_size = (g_op_tab[opc].addr_or_nb == 1) ? 2 : 4;
	while (inst[++i])
	{
		type = param_type(inst[i]);
		if (type == T_REG)
		{
			nb = ft_atoi(inst + 1);
			if (nb > 16 || nb < 1)
				return (0);
			op[n++] = nb;
		}
		else if (type == T_DIR)
		{
			if (inst[i][1] == ':') // CAS D'UN LABEL - PAS GERÉ
				
		}
	}
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
	unsigned char	*ocp;
	int				type;
	int				i;

	i = 0;
	ocp = 0;
	while (i++ <= 3)
	{
		type = param_type(inst[i]);
		type = (type == 4) ? 3 : type;
		ocp += type;
		ocp <<= 2;
	}
	return (ocp);
}

int					get_inst(char **inst, t_lst_op *lst)
{
	static int	nb_oc = 0;
	int 		n;
	int			i;
	int 		oc;

	i = 0;
	n = (inst[0][ft_strlen(inst[0]) - 1] == ':') ? 1 : 0;
	ft_check_label(inst, tab);
	/*
	** Le cas du label en debut de chaine n'est pas gere
	*/
	while (i <= 16 && (ft_strcmp(g_op_tab[i].name, inst[n]) != 0))
		i++;
	if (i == 16 || !(check_params(inst + n, i) == 0))
		return (0); //Erreur instruct
	lst->op[n++] = i + 1;
	if (g_op_tab.opc == TRUE)
		lst->op[n++] = get_ocp(inst + (n - 2));
	if (!(get_params(inst + (n - 3), &lst->op, i, n)))
		return (0);
	nb_oc += n;
	lst->pos = nb_oc;
}

int					check_inst(char *line, t_lst_op *lst)
{
<<<<<<< HEAD
	char	*line;
	char	**inst;
//	t_label	*label;
=======
	char		*line;
	char		**inst;
	t_lst_op	*tmp;
>>>>>>> f4c54acc64efaf95957371e3df5435da10220316

	tmp = lst;
	while (get_next_line(fd, &line) > 0, 16)
	{
		if (ft_split_inst(line))
		{
<<<<<<< HEAD
//			ft_check_label(inst, label); //stock labels in lists.
			if (!(get_inst(inst)))
=======
			if (!(get_inst(inst, tmp)))
>>>>>>> f4c54acc64efaf95957371e3df5435da10220316
				return (0); //Instruction incorrecte
			ft_free_arr(inst);
			tmp = tmp->next;
			if (!(tmp = malloc(sizeof(t_lst_op))))
				return (0);
		}
		free(line);
	}
<<<<<<< HEAD
//	if (ft_double_check_label(label) == -1) //checks label calls for adequate declaration.
//		return (0);
=======
	tmp = NULL;
>>>>>>> f4c54acc64efaf95957371e3df5435da10220316
	return (1);
}
