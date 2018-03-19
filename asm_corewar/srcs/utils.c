/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:05:06 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/19 02:25:50 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** RMP_PARAM - Remplie lst->op avec les parametres en fonction de la taille des
** dir (differente en fonction de l'instruction).
*/

t_lst_op	*rmp_param(int param, t_lst_op *lst, int dir_size)
{
	int d;

	d = (dir_size - 1) * 8;
	while (dir_size > 0)
	{
		lst->op[lst->pos++] = (unsigned char)(param >> d);
		param <<= 8;
		dir_size--;
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
	params = ft_arrnew(5);
	while (inst[n] && inst[n] != '#')
	{
		while (inst[n] == ' ' || inst[n] == '\t' || inst[n] == ',')
			n++;
		while (inst[n + i] && inst[n + i] != ' ' && inst[n + i] != '\t'
		&& inst[n + i] != ',' && inst[n + i] != '#')
			i++;
		if (i > 0)
			params[t++] = ft_strndup(inst + n, i);
		n += i;
		i = 0;
	}
	return (params);
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
		i++;
	if (line[i])
		dest = ft_strsub(line, i, ft_strlen(line));
	free(line);
	return (dest);
}

/*
** FT_BINARY_ITOA - Convertie la valeur unsigned char* en sa valeur binaire
** dans un char*. FONCTION INUTILE.
*/

char		*ft_binary_itoa(unsigned char c, int type) // si type > 0, on aura 0b devant le resultat
{
	int		n;
	char	*nb;
	int		tmp;

	type = (type > 0) ? 2 : 0;
	nb = (char *)malloc(sizeof(char) * 8 + type);
	n = 8 + type;
	nb[n--] = '\0';
	while (n >= type)
	{
		tmp = (c >= 2) ? c % 2 : c;
		nb[n--] = (char)(48 + tmp);
		c /= 2;
	}
	if (type == 2)
	{
		nb[1] = 'b';
		nb[0] = '0';
	}
	return (nb);
}
