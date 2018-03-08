/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:51:51 by mmatime           #+#    #+#             */
/*   Updated: 2017/11/26 19:03:33 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_n(const char *str, int nb)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (str[i])
	{
		trigger = 1;
		i++;
		while (str[i] == '\0' && nb)
		{
			i++;
			nb--;
		}
	}
	if (trigger == 0 && nb)
		i++;
	return (i);
}
