/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 01:38:10 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 10:17:25 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_word(char **dst, char *src, int reset)
{
	static char		*str = NULL;
	static int		word_nb = 0;
	int				ret;

	if (!src || !dst)
		return (-1);
	if (*dst)
		ft_strdel(dst);
	if (reset || str != src)
		word_nb = 0;
	str = src;
	if ((ret = ft_get_word(dst, src, word_nb++)) == 0)
		word_nb = 0;
	return (ret);
}
