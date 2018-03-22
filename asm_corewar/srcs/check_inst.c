/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:54:16 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/22 10:06:17 by lgraham          ###   ########.fr       */
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
				return (inst_error(WRONG_REGISTER, lst->line_nb, inst[i] + 1));
			lst->op[lst->pos++] = (unsigned char)(nb);
		}
		else if (type == T_DIR && inst[i][1] == ':') // CAS D'UN LABEL - PAS GERÉ
			lst = rmp_param(0, lst, dir_size, -1);
		else if (type == T_DIR)
			lst = rmp_param(ft_atoi(inst[i] + 1), lst, dir_size, -1);
		else if (type == T_IND)
			lst = rmp_param(ft_atoi(inst[i]), lst, 2, -1);
	}
	return (1);
}

/*
** CHECK_PARAMS - fonction qui verifie le nombre et le type des parametres
** en fonction de l'instruction.
*/

int					check_params(char **inst, int opcode, int line_nb)
{
	int		n;
	int		type;

	n = -1;
	while (inst[++n])
	{
		if (g_op_tab[opcode].param_nb <= n)
			return (inst_error(TOO_MANY_PARAMS, line_nb, ""));
		type = param_type(inst[n]);
		if (!(type & g_op_tab[opcode].param_type[n]))
			return (inst_error(INVALID_PARAMS, line_nb, ""));
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
	while (i < 16 && (ft_strcmp(g_op_tab[i].name, inst[nbw]) != 0))
		++i;
//	printf("inst = %s, i = %d\n", inst[1], i);
	if (i == 16)
		return (inst_error(INVALID_INST, lst->line_nb, inst[nbw])); //Erreur instruct
	if (!(check_params(inst + ++nbw, i, lst->line_nb)))
		return (0);
//	printf("inst = %s, i = %d\n", inst[1], i);
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

int					check_inst(t_lst_op *lst, int fd, int lnbr)
{
	t_label		*label_lst;
	char 		*line;
	char		**inst;
	t_lst_op	*tmp;
	int 		 i;

	i = 0;
	tmp = lst;
	tmp->line_nb = lnbr + 1;
	label_lst = NULL;
	line = NULL;
//	printf("check_inst\n");
	while ((i = get_next_line(fd, &line, 64)) > 0)
	{
		lnbr++;
//		printf("%d : %s\n", i, line);
		if (line && (inst = ft_split_inst(line)) != NULL)
		{
			i++;
			if (!get_inst(inst, tmp) || (!(label_lst = check_label(inst, label_lst, tmp->pos, i))))
			{
				ft_free_arr(inst);
				return (0); //Instruction incorrecte
			}
			ft_free_arr(inst);
			if ((tmp->next = init_lst(lnbr)) == NULL)
				return (0);
			tmp = tmp->next;
		}
//		free(line);
	}
	calc_dist_label(label_lst, tmp);
	replace_dist(label_lst, lst);
	free(line);
	 //AFFICHAGE TEMPORAIRE DES LABELS 
	aff_label(label_lst);
	i = 0;
	while (lst)
	{
		while (i < lst->pos)
		{
			ft_printf("%02x ", lst->op[i++]);
		}
		ft_putchar('\n');
		i = 0;
		lst = lst->next;
	}
	return (1);
}
