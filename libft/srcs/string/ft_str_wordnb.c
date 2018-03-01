/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_wordnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 08:39:23 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 20:09:50 by gudemare         ###   ########.fr       */
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

size_t			ft_str_wordnb(char *str)
{
	size_t		word_nb;

	if (!str)
		return ((size_t)-1);
	word_nb = 0;
	str = skip_whitespaces(str);
	while (*str)
	{
		str = skip_characters(str);
		str = skip_whitespaces(str);
		word_nb++;
	}
	return (word_nb);
}
