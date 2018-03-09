/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:36:35 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:45:29 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc <= 127)
		ft_putchar_fd((char)(wc), fd);
	else if (wc <= 2047)
	{
		ft_putchar_fd((char)((wc >> 6) + 0xC0), fd);
		ft_putchar_fd((char)((wc & 0x3F) + 0x80), fd);
	}
	else if (wc <= 65535)
	{
		ft_putchar_fd((char)((wc >> 12) + 0xE0), fd);
		ft_putchar_fd((char)(((wc >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_fd((char)((wc & 0x3F) + 0x80), fd);
	}
	else if (wc <= 1114111)
	{
		ft_putchar_fd((char)((wc >> 18) + 0xF0), fd);
		ft_putchar_fd((char)(((wc >> 12) & 0x3F) + 0x80), fd);
		ft_putchar_fd((char)(((wc >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_fd((char)((wc & 0x3F) + 0x80), fd);
	}
}
