/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:27:11 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/15 01:05:35 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_format(const char *restrict str, char **format)
{
	int		i;
	char	*c;

	i = 0;
	*format = 0;
	while (str[i] && ft_strchr("#0- +'", str[i]))
		i++;
	if (i == 0)
		return (0);
	ft_assert(*format = ft_strndup(str, i));
	while (ft_strchr(*format, '+') && (c = ft_strchr(*format, ' ')))
		*c = '+';
	while (ft_strchr(*format, '-') && (c = ft_strchr(*format, '0')))
		*c = '-';
	return (i);
}

static int	fill_width(const char *restrict str, t_spec *spec, va_list ap)
{
	int		i;
	int		ret;

	i = 0;
	spec->min_width = 0;
	while (ft_isdigit(str[i]) || str[i] == '*')
		i++;
	ret = i;
	if (i > 0 && ft_strchr(str, '*') && ft_strchr(str, '*') < str + i)
		if ((spec->min_width = va_arg(ap, int)) < 0)
		{
			spec->min_width *= -1;
			ft_assert(spec->format = (spec->format) ?
					ft_strjoin(spec->format, "-") : ft_strdup("-"));
		}
	i -= (i == 0) ? 0 : 1;
	while (ft_isdigit(str[i]))
		i--;
	if (ret > 0 && i < ret - 1)
		spec->min_width = ft_atoi(str + i + 1);
	return (ret);
}

static int	fill_precision(const char *restrict str, t_spec *spec, va_list ap)
{
	int		i;

	spec->precision = -1;
	if (*str != '.')
		return (0);
	i = 1;
	if (str[1] == '*')
	{
		if ((spec->precision = va_arg(ap, int)) < 0)
			spec->precision = -1;
	}
	else
		spec->precision = ft_atoi(str + 1);
	while (ft_isdigit(str[i]) || str[i] == '*')
		i++;
	return (i);
}

static int	fill_length(const char *restrict str, char **length)
{
	int		i;

	i = 0;
	*length = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		i++;
	if (i != 0)
		ft_assert(*length = ft_strndup(str, i));
	return (i);
}

int			fill_spec(const char *restrict str, t_spec *spec, va_list ap)
{
	int		i;

	i = 1;
	i += fill_format(str + i, &(spec->format));
	i += fill_width(str + i, spec, ap);
	i += fill_precision(str + i, spec, ap);
	i += fill_length(str + i, &(spec->length));
	spec->conv = str[i];
	if (spec->conv && ft_strchr("COUDS", (int)spec->conv))
	{
		spec->conv = ft_tolower(spec->conv);
		if (spec->length && !(ft_strchr(spec->length, (int)'l')))
			ft_assert(spec->length = ft_strjoin(spec->length, "l"));
		else if (!spec->length)
			ft_assert(spec->length = ft_strdup("l"));
	}
	return (i + 1);
}
