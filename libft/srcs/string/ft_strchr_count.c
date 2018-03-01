/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:57:13 by gudemare          #+#    #+#             */
/*   Updated: 2017/08/11 10:59:51 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_count(const char *s, int ch)
{
	char	c;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	c = (char)ch;
	while (s[i])
		if (s[i++] == ch)
			ret++;
	return (ret);
}
