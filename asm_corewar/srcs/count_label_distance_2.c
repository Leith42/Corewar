/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_label_distance_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:03:17 by gudemare          #+#    #+#             */
/*   Updated: 2018/04/11 05:39:47 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check si un char interdit est présent dans un label
*/

int		char_label_is_valid(char *str, int n)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((n != 0 && i == 0 && str[i] == DIRECT_CHAR))
			i++;
		if ((n != 0 && i < 2 && str[i] == LABEL_CHAR))
			i++;
		if (n == 0 && i == (int)ft_strlen(str) - 1 && str[i] == LABEL_CHAR)
			break ;
		else if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Si cette ft retourne 1, le label est TOUJOURS codé sur 2 octs
*/

int		only_on_two(char op)
{
	if (op == 3 || op == 9 || op == 10 || op == 11
			|| op == 12 || op == 14 || op == 15)
		return (1);
	return (0);
}

/*
** Détermine si le label doit etre codé sur 2 ou 4 octs
*/

void	set_by_type(int *dir_size, int *final_place, int type)
{
	if (type == 2)
	{
		*dir_size = 2;
		*final_place += 1;
	}
	else
	{
		*dir_size = 4;
		*final_place += 3;
	}
}

/*
** Ajoute la value au bon endroit dans la liste d'instructions
*/

void	add_value_to_inst(int res, t_lst_op *lst_node,
		int pos_tmp, int type)
{
	int i;
	int final_place;
	int dir_size;

	i = 0;
	final_place = lst_node->label_pos[pos_tmp];
	if (lst_node->op[0] == 1)
	{
		dir_size = 4;
		final_place += 3;
	}
	else if (only_on_two((char)lst_node->op[0]))
	{
		dir_size = 2;
		final_place++;
	}
	else
		set_by_type(&dir_size, &final_place, type);
	while (i < dir_size)
	{
		lst_node->op[final_place] = (unsigned char)res;
		final_place--;
		res >>= 8;
		i++;
	}
}

/*
** Calcule et renvoi la valeur entre le call et sa déclaration
*/

int		calculate_res(t_lst_op *tmp_lst, t_label *tmp_label, int line)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < line)
	{
		res += tmp_lst->pos;
		tmp_lst = tmp_lst->next;
		i++;
	}
	tmp_label->is_set = 1;
	return (res);
}
