/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:47:03 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/06 15:47:05 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_write(char *file_name, unsigned char *tab)
{
	int n;

	n = -1;
	//fonction qui change file_name.s en file_name.cor
	//creation file_name
	while (tab[++n])
	{
		//convertir unsigned char en binaire
		//write binaire dans file_name
	}
	return (1);
}
