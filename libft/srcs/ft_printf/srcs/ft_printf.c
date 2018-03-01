/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:10 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/16 00:43:45 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_vdprintf(int fd, const char *restrict str, va_list ap)
{
	int			i;
	int			ret;
	t_conv_ptr	*conv_list;

	ret = 0;
	conv_list = fill_conv_list();
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		ft_putnstr_fd(str, fd, i);
		ret += i;
		str += i;
		if (*str == '%')
			ret += handle_conv(conv_list, &str, ap, fd);
	}
	free(conv_list);
	return (ret);
}

int					ft_dprintf(int fd, const char *restrict str, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, str);
	ret = ft_vdprintf(fd, str, ap);
	va_end(ap);
	return (ret);
}

int					ft_vprintf(const char *restrict str, va_list ap)
{
	return (ft_vdprintf(1, str, ap));
}

int					ft_printf(const char *restrict str, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, str);
	ret = ft_vdprintf(1, str, ap);
	va_end(ap);
	return (ret);
}
