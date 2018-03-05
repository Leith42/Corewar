/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:52:18 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/15 23:57:58 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_separator(char *buf)
{
	int		init_i;
	int		i;
	int		j;
	int		nb_sep;

	i = 0;
	while (buf[i] && (buf[i] == '0' || !ft_isdigit(buf[i])))
		i++;
	nb_sep = (ft_strlen(buf) - i - 1) / 3;
	init_i = ft_strlen(buf) + nb_sep;
	i = init_i - 1;
	j = ft_strlen(buf) - 1;
	ft_assert(buf = ft_strextend(buf, nb_sep));
	while (i >= 0)
	{
		if ((init_i - i) % 4 == 0 && i != 0)
			buf[i] = ',';
		else
			buf[i] = buf[j--];
		i--;
	}
	return (buf);
}

static char	*apply_sign(char *s, char *format)
{
	char	*buf;

	if (!ft_isdigit(*s))
		return (s);
	ft_assert(buf = ft_strnew(ft_strlen(s) + 1));
	ft_strcpy(buf + 1, s);
	ft_strdel(&s);
	*buf = (ft_strchr(format, '+')) ? '+' : ' ';
	return (buf);
}

static char	*apply_pre(char *s, int precision)
{
	char	*buf;
	int		is_signed;

	is_signed = 1 - ft_isdigit(*s);
	ft_assert(buf = ft_strnew(precision + is_signed));
	if (is_signed)
	{
		*buf = *s;
		buf++;
		s++;
	}
	ft_memset((void*)buf, '0', precision);
	ft_strcpy(buf + precision - ft_strlen(s), s);
	s -= is_signed;
	ft_strdel(&s);
	return (buf - is_signed);
}

static char	*apply_mfw(char *s, t_spec spec)
{
	char	*buf;

	if (spec.precision == -1 && spec.format && ft_strchr(spec.format, '0'))
		return (apply_pre(s, spec.min_width + ft_isdigit(*s) - 1));
	ft_assert(buf = ft_strnew(spec.min_width));
	ft_memset((void*)buf, ' ', spec.min_width);
	if (spec.format && ft_strchr(spec.format, (int)'-'))
		ft_strncpy(buf, s, ft_strlen(s));
	else
		ft_strcpy(buf + spec.min_width - ft_strlen(s), s);
	ft_strdel(&s);
	return (buf);
}

int			conv_d(va_list ap, t_spec spec, int fd)
{
	char	*buf;
	int		ret;

	ft_assert(buf = ft_anytoa(get_di_arg(ap, spec.length)));
	if (spec.format
			&& (ft_strchr(spec.format, ' ') || ft_strchr(spec.format, '+')))
		buf = apply_sign(buf, spec.format);
	if ((spec.precision == 0 && *buf == '0')
			|| spec.precision > (int)ft_strlen(buf) + ft_isdigit(*buf) - 1)
		buf = apply_pre(buf, spec.precision);
	if (spec.format && ft_strchr(spec.format, '\''))
		buf = apply_separator(buf);
	if (spec.min_width > (int)ft_strlen(buf))
		buf = apply_mfw(buf, spec);
	ft_putstr_fd(buf, fd);
	ret = ft_strlen(buf);
	ft_strdel(&buf);
	return (ret);
}
