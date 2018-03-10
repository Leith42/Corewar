/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:03 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/08 10:04:26 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		ft_write(char *file_name, unsigned char *tab)
{
	int n;
	char *new_file_name;

	n = -1;
	new_file_name = ft_strjoin(ft_strndup(file_name, ft_strlen(file_name) - 2), ".cor"); // degueulasse mais c'est l'idée :)
	ft_putendl(new_file_name);
	(void)tab;
	//creation file_name
	/*while (tab[++n])
	{
		//convertir unsigned char en binaire
		//write binaire dans file_name
	}*/
	return (1);
}
