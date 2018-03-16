/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:54:16 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/16 01:12:34 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** GET_PARAMS - fonction qui ecris les parametres dans le lst->op.
*/

int					get_params(char	**inst, t_lst_op *lst, int opc)
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
			nb = ft_atoi(inst[i] + 1);
			if (nb > 16 || nb < 1)
				return (0);
			lst->op[lst->pos++] = (unsigned char)(nb);
		}
		else if (type == T_DIR && inst[i][1] == ':') // CAS D'UN LABEL - PAS GERÉ
			lst = rmp_param(69, lst, dir_size);
		else if (type == T_DIR)
			lst = rmp_param(ft_atoi(inst[i] + 1), lst, dir_size);
		else if (type == T_IND)
			lst = rmp_param(ft_atoi(inst[i]), lst, 2);
	}
	return (1);
}

/*
** CHECK_PARAMS - fonction qui verifie le nombre et le type des parametres
** en fonction de l'instruction.
*/

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
	return ((g_op_tab[opcode].param_nb == n) ? 1 : 0);
}

/*
** GET_OCP - fonction qui calcule l'octet de codage des parametres et le
** stock dans lst->op;
*/

unsigned char		get_ocp(char **inst)
{
	unsigned char	ocp;
	int				type;
	int				i;

	i = -1;
	ocp = 0;
	while (++i != 3)
	{
		type = param_type(inst[i]);
		type = (type == 4) ? 3 : type;
		ocp += type;
		ocp <<= (unsigned char)2;
	}
	return (ocp);
}

/*
** GET_INST - fonction qui renvoie l'instruction et ses params vers les
** fonctions qui vont les verifier et les stocker dans lst->op.
*/

int					get_inst(char **inst, t_lst_op *lst)
{
	static int	nb_oc = 0;
	int			i;
	int			nbw;

	lst->pos = 0;
	i = 0;
	nbw = (inst[0][ft_strlen(inst[0]) - 1] == ':') ? 1 : 0;
	/*
	** Le cas du label en debut de chaine n'est pas gere - ft_check_label(inst, tab);
	*/
	while (i <= 16 && (ft_strcmp(g_op_tab[i].name, inst[nbw]) != 0))
		i++;
	if (i == 16 || (check_params(inst + ++nbw, i) == 0))
		return (0); //Erreur instruct
	lst->op[lst->pos++] = i + 1;
	if (g_op_tab[i].ocp == 1 && lst->pos++)
		lst->op[lst->pos - 1] = get_ocp(inst + nbw);
	if (!(get_params(inst + nbw, lst, i)))
		return (0);
	nbw = 0;

	/* AFFICHAGE TEMPORAIRE */
	while (nbw < lst->pos)
		printf("%02x ", lst->op[nbw++]);
	printf("\n");
	nb_oc += lst->pos;

	return (1);
}

/*
** CHECK_INST - fonction qui lis le fichier ligne par ligne et qui creer **inst
** et qui renvoie chaque ligne ainsi separer vers get_inst.
*/

int					check_inst(char *line, t_lst_op *lst, int fd)
{
	t_label		*label;
	char		**inst;
	t_lst_op	*tmp;

	tmp = lst;
	label = NULL;
	while ((get_next_line(fd, &line, 16)) > 0)
	{
		//printf("line = %s\n", line);
		if ((inst = ft_split_inst(line)) != NULL)
		{
			check_label(inst, label); //stock labels in lists.
			if (!(get_inst(inst, tmp)))
			{
				ft_free_arr(inst);
				return (0); //Instruction incorrecte
			}
			ft_free_arr(inst);
			if (!(tmp->next = malloc(sizeof(t_lst_op))))
				return (0);
			tmp = tmp->next;
		}
	}
	free(line);
	if (double_check_label(label) == -1) //checks label calls for adequate declaration.
		return (0);
	tmp = NULL;
	return (1);
}
