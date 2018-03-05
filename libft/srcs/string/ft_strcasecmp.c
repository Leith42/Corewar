/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:19:53 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/22 04:04:51 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i]
		&& (unsigned char)ft_toupper((int)s1[i])
		== (unsigned char)ft_toupper((int)s2[i]))
		i++;
	return ((int)((unsigned char)ft_toupper((int)s1[i])
	- (unsigned char)ft_toupper((int)s2[i])));
}
