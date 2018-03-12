/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:05:06 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/12 16:05:09 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

char		*epur_str_beginning(char *line) // supprime les espaces en debut de ligne
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
