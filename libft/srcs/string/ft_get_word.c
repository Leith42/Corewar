/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 06:18:06 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:58:19 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*skip_characters(char *str)
{
	while (*str && !ft_is_whitespace(*str))
		str++;
	return (str);
}

static char		*skip_whitespaces(char *str)
{
	while (*str && ft_is_whitespace(*str))
		str++;
	return (str);
}

int				ft_get_word(char **dst, char *str, int word_nb)
{
	char	*end;

	if (!dst)
		return (-1);
	if (*dst)
		ft_strdel(dst);
	str = skip_whitespaces(str);
	while (word_nb-- > 0)
	{
		str = skip_characters(str);
		str = skip_whitespaces(str);
		if (!(str))
			return (0);
	}
	end = skip_characters(str);
	if (!(*dst = ft_strsub(str, 0, (size_t)(end - str))))
		return (-1);
	if (ft_is_str_ws(end))
		return (0);
	return (1);
}
