/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:38:10 by mmatime           #+#    #+#             */
/*   Updated: 2018/01/02 13:17:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_n(const char *s, int nb)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] == '\0' && nb)
	{
		write(1, &s[i], 1);
		i++;
		nb--;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		while (s[i] == '\0' && nb)
		{
			write(1, &s[i], 1);
			i++;
			nb--;
		}
	}
}
