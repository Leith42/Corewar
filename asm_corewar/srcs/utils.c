/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:05:06 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/22 10:03:17 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** RMP_PARAM - Remplie lst->op avec les parametres en fonction de la taille des
** dir (differente en fonction de l'instruction).
*/

t_lst_op	*rmp_param(int param, t_lst_op *lst, int dir_size, int res)
{
	int d;

	if (res != -1)
	{
		d = (dir_size - 1) * 8;
		while (dir_size > 0)
		{
			lst->op[res++] = (unsigned char)(param >> d);
			param <<= 8;
			dir_size--;
		}
	}
	else
	{
		d = (dir_size - 1) * 8;
		while (dir_size > 0)
		{
			lst->op[lst->pos++] = (unsigned char)(param >> d);
			param <<= 8;
			dir_size--;
		}
	}
	return (lst);
}

/*
** PARAM_TYPE - Renvoie 0, T_REG, T_DIR ou T_IND en fonction du type du param.
*/

int			param_type(char *param)
{
	if (!param)
		return (0);
	if (param[0] == 'r')
		return (T_REG);
	if (param[0] == '%')
		return (T_DIR);
	return (T_IND);
}

/*
** FT_SPLIT_INST - Separe une ligne d'instruction par "mot" en fonction des
** tabulations, espaces et virgules.
*/

char		**ft_split_inst(char *inst)
{
	char	**params;
	int		n;
	int		i;
	int		t;

	n = 0;
	i = 0;
	t = 0;
	params = ft_arrnew(7);
	while (inst[n] && inst[n] != '#' && t < 7)
	{
		while (inst[n] == ' ' || inst[n] == '\t' || inst[n] == ',')
			++n;
		while (inst[n + i] && inst[n + i] != ' ' && inst[n + i] != '\t'
&& inst[n + i] != ',' && inst[n + i] != '#' && (t != 0 || inst[n + i] != ':'))
			++i;
		i += (inst[n + i] == ':') ? 1 : 0;
		if (i > 0)
			params[t++] = ft_strndup(inst + n, i);
		n += i;
		i = 0;
	}
	return ((t > 0) ? params : NULL);
}

/*
** EPUR_STR_BEGINNING - Enleve les espaces en debut de ligne dans un char*.
*/

char		*epur_str_beginning(char *line)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while ((line[i] && line[i] == ' ') || (line[i] && line[i] == '\t'))
		++i;
	if (line[i])
		dest = ft_strsub(line, i, ft_strlen(line));
	free(line);
	return (dest);
}
