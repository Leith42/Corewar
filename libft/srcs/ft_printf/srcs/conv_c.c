/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:22:43 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/15 23:57:31 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static	wchar_t	*apply_wmfw(wchar_t wc, t_spec spec)
{
	wchar_t	*wbuf;
	wchar_t	wc_padding;

	ft_assert(wbuf = (wchar_t*)malloc(
				sizeof(wchar_t) * (spec.min_width - ft_wcharsize(wc))));
	wc_padding = (spec.format &&
			ft_strchr(spec.format, (int)'0')) ? L'0' : L' ';
	ft_wmemset(wbuf, wc_padding, (size_t)spec.min_width);
	if (spec.format != NULL && ft_strchr(spec.format, (int)'-'))
		wbuf[0] = wc;
	else
		wbuf[spec.min_width - ft_wcharsize(wc)] = wc;
	return (wbuf);
}

static	int		conv_wc(va_list ap, t_spec spec, int fd)
{
	wchar_t	*wbuf;
	wchar_t	wc;
	int		ret;

	if (spec.conv != 'c')
		wc = (wchar_t)spec.conv;
	else
		wc = (wchar_t)va_arg(ap, wint_t);
	if (spec.min_width > ft_wcharsize(wc))
	{
		wbuf = apply_wmfw(wc, spec);
		ret = spec.min_width;
		ft_putwnstr_fd(wbuf, (size_t)spec.min_width - ft_wcharsize(wc) + 1, fd);
		free(wbuf);
	}
	else
	{
		ft_putwchar_fd(wc, fd);
		ret = ft_wcharsize(wc);
	}
	return (ret);
}

static char		*apply_mfw(char c, t_spec spec)
{
	char	*buf;
	char	c_padding;

	ft_assert(buf = ft_strnew(spec.min_width));
	c_padding = (spec.format && ft_strchr(spec.format, (int)'0')) ? '0' : ' ';
	ft_memset((void*)buf, c_padding, spec.min_width);
	if (spec.format != NULL && ft_strchr(spec.format, (int)'-'))
		buf[0] = c;
	else
		buf[spec.min_width - 1] = c;
	return (buf);
}

int				conv_c(va_list ap, t_spec spec, int fd)
{
	char	*buf;
	char	c;
	int		ret;

	if ((spec.length && ft_strchr(spec.length, 'l')) || spec.conv < 0)
		return (conv_wc(ap, spec, fd));
	if (spec.conv != 'c')
		c = spec.conv;
	else
		c = (unsigned char)va_arg(ap, int);
	if (spec.min_width > 1)
	{
		buf = apply_mfw(c, spec);
		ret = spec.min_width;
		write(fd, buf, (size_t)spec.min_width);
		ft_strdel(&buf);
	}
	else
	{
		ft_putchar_fd(c, fd);
		ret = 1;
	}
	return (ret);
}
