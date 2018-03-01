/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:52:27 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/16 00:16:04 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	wchar_t	*apply_wmfw(wchar_t *ws, t_spec spec)
{
	wchar_t	*wbuf;
	wchar_t	wc_padding;
	int		len;

	len = spec.min_width - ft_wstrsize(ws) + ft_wstrlen(ws);
	ft_assert(wbuf = (wchar_t*)malloc((len + 1) * sizeof(wchar_t)));
	wc_padding = (spec.format &&
			ft_strchr(spec.format, (int)'0')) ? L'0' : L' ';
	ft_wmemset(wbuf, wc_padding, len);
	wbuf[len] = L'\0';
	if (spec.format && ft_strchr(spec.format, (int)'-'))
		ft_wstrncpy(wbuf, ws, ft_wstrlen(ws));
	else
		ft_wstrncpy(wbuf + len - ft_wstrlen(ws), ws,
				ft_wstrlen(ws));
	free(ws);
	return (wbuf);
}

static	void	apply_wpre(wchar_t *ws, int precision)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < precision)
	{
		if (ft_wcharsize(ws[j]) + i > precision)
			break ;
		i += ft_wcharsize(ws[j]);
		j++;
	}
	ws[j] = L'\0';
}

static	int		conv_ws(va_list ap, t_spec spec, int fd)
{
	wchar_t	*wbuf;
	int		ret;

	wbuf = va_arg(ap, wchar_t*);
	ft_assert(wbuf = ft_wstrdup((wbuf) ? wbuf : L"(null)"));
	if (spec.precision > -1 && spec.precision < ft_wstrsize(wbuf))
		apply_wpre(wbuf, spec.precision);
	if (spec.min_width > ft_wstrsize(wbuf))
		wbuf = apply_wmfw(wbuf, spec);
	ft_putwnstr_fd(wbuf, ft_wstrlen(wbuf), fd);
	ret = ft_wstrsize(wbuf);
	free(wbuf);
	return (ret);
}

static char		*apply_mfw(char *s, t_spec spec)
{
	char	*buf;
	char	c_padding;

	ft_assert(buf = ft_strnew(spec.min_width));
	c_padding = (spec.format && ft_strchr(spec.format, (int)'0')) ? '0' : ' ';
	ft_memset((void*)buf, c_padding, spec.min_width);
	if (spec.format && ft_strchr(spec.format, (int)'-'))
		ft_strncpy(buf, s, ft_strlen(s));
	else
		ft_strcpy(buf + spec.min_width - ft_strlen(s), s);
	ft_strdel(&s);
	return (buf);
}

int				conv_s(va_list ap, t_spec spec, int fd)
{
	char	*buf;
	int		ret;

	if (spec.length && ft_strchr(spec.length, 'l'))
		return (conv_ws(ap, spec, fd));
	buf = (char *)va_arg(ap, char*);
	ft_assert(buf = ft_strdup((buf) ? buf : "(null)"));
	if (spec.precision > -1 && (size_t)spec.precision < ft_strlen(buf))
		buf[spec.precision] = '\0';
	if ((size_t)spec.min_width > ft_strlen(buf))
		buf = apply_mfw(buf, spec);
	ft_putstr_fd(buf, fd);
	ret = ft_strlen(buf);
	ft_strdel(&buf);
	return (ret);
}
