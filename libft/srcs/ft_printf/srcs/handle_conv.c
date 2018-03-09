/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 00:42:47 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/16 00:43:45 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_conv(const t_conv_ptr *conv_list,
		const char *restrict *str, va_list ap, int fd)
{
	t_spec		spec;
	int			ret;
	int			i;

	*str += fill_spec(*str, &spec, ap);
	if (spec.conv && (i = ft_strchr_loc("cdiopsuxX%", (int)spec.conv)) != -1)
		ret = (conv_list[i])(ap, spec, fd);
	else if (spec.conv)
		ret = conv_c(ap, spec, fd);
	else
	{
		*str -= 1;
		ret = 0;
	}
	ft_strdel(&spec.format);
	ft_strdel(&spec.length);
	return (ret);
}

t_conv_ptr	*fill_conv_list(void)
{
	t_conv_ptr	*conv_list;

	ft_assert(conv_list = malloc(sizeof(t_conv_ptr) * 10));
	conv_list[0] = &conv_c;
	conv_list[1] = &conv_d;
	conv_list[2] = &conv_d;
	conv_list[3] = &conv_o;
	conv_list[4] = &conv_p;
	conv_list[5] = &conv_s;
	conv_list[6] = &conv_u;
	conv_list[7] = &conv_x;
	conv_list[8] = &conv_x;
	conv_list[9] = &conv_c;
	return (conv_list);
}
