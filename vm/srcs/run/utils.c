/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:06:58 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/10 06:46:25 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

static char		*get_champ_color(t_env *env, unsigned int id)
{
	if (id == NULL_ID)
		return ("\x1b[2;37m");
	else if (id == env->champions[0].id)
		return (COLOR_P1);
	else if (env->nb_of_champions > 1 && id == env->champions[1].id)
		return (COLOR_P2);
	else if (env->nb_of_champions > 2 && id == env->champions[2].id)
		return (COLOR_P3);
	else if (env->nb_of_champions > 3 && id == env->champions[3].id)
		return (COLOR_P4);
	ft_free_exit(*env, "Bad ID in mask !\n", 0, 0);
	return (NULL);
}

/*
** Gets back high or low 4 bytes of input in hex format.
*/

static char		get_hex_byte(unsigned char byte, int high)
{
	unsigned char	cur;

	if (high)
		cur = byte >> 4;
	else
		cur = byte & 15;
	if (cur < 10)
		cur += '0';
	else
		cur = cur - 10 + 'A';
	return ((char)cur);
}

/*
** Displays current arena state in lines of line_len bytes in hex format.
** Very heavy on speed of battle, so may end optimized and less readable.
*/

void			disp_arena(t_env *env, size_t line_len)
{
	static char	*tmp = NULL;
	size_t		i;
	size_t		len;

	if (tmp == NULL && !(tmp = ft_strnew(14 * 64)))
		ft_free_exit(*env, "Not enough memory", 1, 0);
	i = 0;
	ft_putstr("\x1b[H");
	while (i < MEM_SIZE)
	{
		tmp = ft_strcat(tmp, get_champ_color(env, env->mask[i]));
		len = ft_strlen(tmp);
		tmp[len] = get_hex_byte(env->arena[i], 1);
		tmp[len + 1] = get_hex_byte(env->arena[i], 0);
		tmp = ft_strcat(tmp, " \x1b[0m");
		i++;
		if ((i % line_len) == 0)
		{
			tmp = ft_strcat(tmp, "\n");
			ft_putstr(tmp);
			ft_strclr(tmp);
		}
	}
	ft_strdel(&tmp);
}

unsigned int	ft_lstlen(t_list *lst)
{
	unsigned int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

char			*get_champ_name(t_env *env, unsigned int id)
{
	char	*res;
	size_t	i;

	res = NULL;
	i = 0;
	while (i < env->nb_of_champions)
	{
		if (env->champions[i].id == id)
		{
			res = env->champions[i].header.prog_name;
			break ;
		}
		i++;
	}
	return (res);
}
