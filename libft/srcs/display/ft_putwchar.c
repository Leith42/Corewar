/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:36:05 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:43:50 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 127)
		ft_putchar((char)wc);
	else if (wc <= 2047)
	{
		ft_putchar((char)((wc >> 6) + 0xC0));
		ft_putchar((char)((wc & 0x3F) + 0x80));
	}
	else if (wc <= 65535)
	{
		ft_putchar((char)((wc >> 12) + 0xE0));
		ft_putchar((char)(((wc >> 6) & 0x3F) + 0x80));
		ft_putchar((char)((wc & 0x3F) + 0x80));
	}
	else if (wc <= 1114111)
	{
		ft_putchar((char)((wc >> 18) + 0xF0));
		ft_putchar((char)(((wc >> 12) & 0x3F) + 0x80));
		ft_putchar((char)(((wc >> 6) & 0x3F) + 0x80));
		ft_putchar((char)((wc & 0x3F) + 0x80));
	}
}
