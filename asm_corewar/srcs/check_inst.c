/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:54:16 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/05 03:59:18 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** GET_PARAMS - fonction qui ecris les parametres dans le lst->op.
*/

static int				get_params(char **inst, t_lst_op *lst, int opc)
{
	int		dir_size;
	int		i;
	int		type;
	int		nb;

	i = -1;
	dir_size = (g_op_tab[opc].addr_or_nb == 1) ? 2 : 4;
	while (inst[++i])
	{
		if ((type = param_type(inst[i])) && type == T_REG)
		{
			nb = ft_atoi(inst[i] + 1);
			if (nb > 16 || nb < 1)
				return (inst_error(WRONG_REGISTER, lst->line_nb, inst[i] + 1));
			lst->op[lst->pos++] = (unsigned char)(nb);
		}
		else if ((type == T_DIR && inst[i][1] == ':') ||
		(type == T_IND && inst[i][0] == ':'))
			lst = rmp_param(0, lst, (type == T_IND) ? 2 : dir_size, 1);
		else if (type == T_DIR)
			lst = rmp_param(ft_atoi(inst[i] + 1), lst, dir_size, 0);
		else if (type == T_IND)
			lst = rmp_param(ft_atoi(inst[i]), lst, 2, 0);
	}
	return (1);
}

/*
** CHECK_PARAMS - fonction qui verifie le nombre et le type des parametres
** en fonction de l'instruction.
*/

static int				check_params(char **inst, int opcode, int line_nb)
{
	int		n;
	int 	i;
	int		type;

	n = -1;
	i = 1;
	while (inst[++n])
	{
		if (g_op_tab[opcode].param_nb <= n)
			return (inst_error(TOO_MANY_PARAMS, line_nb, ""));
		type = param_type(inst[n]);
		if ((type == T_DIR && inst[n][1] != ':') || (type == T_REG))
			while (inst[n][i])
				if (!ft_isdigit(inst[n][i++]))
					return (inst_error(SYNTAX_ERROR, line_nb, inst[n]));
		if (!(type & g_op_tab[opcode].param_type[n]))
			return (inst_error(INVALID_PARAMS, line_nb, ""));
	}
	return ((g_op_tab[opcode].param_nb == n) ? 1 : 0);
}

/*
** GET_OCP - fonction qui calcule l'octet de codage des parametres et le
** stock dans lst->op;
*/

static unsigned char	get_ocp(char **inst)
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

static int				get_inst(char **inst, t_lst_op *lst, int *line)
{
	static int	nb_oc = 0;
	int			i;
	int			nbw;

	lst->pos = 0;
	i = 0;
	nbw = (inst[0][ft_strlen(inst[0]) - 1] == ':') ? 1 : 0;
	if (nbw == 1 && inst[nbw + 1] == NULL && (*line -= 1))
		return (1);
	while (i < 16 && (ft_strcmp(g_op_tab[i].name, inst[nbw]) != 0))
		++i;
	if (i == 16)
		return (inst_error(INVALID_INST, lst->line_nb, inst[nbw]));
	if (!(check_params(inst + ++nbw, i, lst->line_nb)))
		return (0);
	lst->op[lst->pos++] = (unsigned char)(i + 1);
	if (g_op_tab[i].ocp == 1 && lst->pos++)
		lst->op[lst->pos - 1] = get_ocp(inst + nbw);
	if (!(get_params(inst + nbw, lst, i)))
		return (0);
	nb_oc += lst->pos;
	return (1);
}

void				aff_label(t_label *label_lst)
{
	while (label_lst)
	{
		printf("label >%s< de type >%d<\n", label_lst->name, label_lst->type);
		label_lst = label_lst->next;
	}
}

/*
** CHECK_INST - fonction qui lis le fichier ligne par ligne et qui creer **inst
** et qui renvoie chaque ligne ainsi separer vers get_inst.
*/

int						check_inst(t_lst_op *lst, int fd)
{
	t_label		*label_lst;
	char		*line;
	char		**inst;
	t_lst_op	*tmp;
	int			i;

	tmp = lst;
	label_lst = NULL;
	line = NULL;
	i = 0;
	while (((get_next_line(fd, &line, 64)) > 0) && lst->line_nb++)
	{
		if (line && (inst = ft_split_inst(line)) != NULL && ++i)
		{
			if ((!get_inst(inst, tmp, &i) || (check_label(inst) &&
(!(label_lst = set_label(inst, label_lst, tmp->pos, i))))) && ft_free_arr(inst))
				return (0); //Instruction incorrecte
			if (lst->pos != 0 && (tmp->next = init_lst(tmp->line_nb)) == NULL)
				return (0);
			tmp = (lst->pos != 0) ? tmp->next : tmp;
		}
	}
	free(line);
	aff_label(label_lst);
	return ((!fill_label(label_lst, lst)) ? 0 : 1);
}
