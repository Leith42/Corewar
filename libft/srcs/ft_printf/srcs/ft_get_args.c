/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 07:21:18 by gudemare          #+#    #+#             */
/*   Updated: 2017/06/25 09:40:41 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			get_di_arg(va_list ap, char *length)
{
	if (!length)
		return ((long long)va_arg(ap, int));
	else if (ft_strstr(length, "z"))
		return ((long long)va_arg(ap, size_t));
	else if (ft_strstr(length, "j"))
		return ((long long)va_arg(ap, intmax_t));
	else if (ft_strstr(length, "ll"))
		return (va_arg(ap, long long));
	else if (ft_strstr(length, "l"))
		return ((long long)va_arg(ap, long));
	else if (ft_strstr(length, "hh"))
		return ((long long)(signed char)va_arg(ap, int));
	else if (ft_strstr(length, "h"))
		return ((long long)(short)va_arg(ap, int));
	exit(EXIT_FAILURE);
}

unsigned long long	get_oux_arg(va_list ap, char *length)
{
	if (!length)
		return ((unsigned long long)va_arg(ap, unsigned int));
	else if (ft_strstr(length, "z"))
		return ((unsigned long long)va_arg(ap, size_t));
	else if (ft_strstr(length, "j"))
		return ((unsigned long long)va_arg(ap, uintmax_t));
	else if (ft_strstr(length, "ll"))
		return (va_arg(ap, unsigned long long));
	else if (ft_strstr(length, "l"))
		return ((unsigned long long)va_arg(ap, unsigned long));
	else if (ft_strstr(length, "hh"))
		return ((unsigned long long)(unsigned char)va_arg(ap, int));
	else if (ft_strstr(length, "h"))
		return ((unsigned long long)(unsigned short)va_arg(ap, int));
	exit(EXIT_FAILURE);
}

void				*get_n_arg(va_list ap, char *length)
{
	if (!length)
		return ((void *)va_arg(ap, int *));
	else if (ft_strstr(length, "z"))
		return ((void *)va_arg(ap, size_t *));
	else if (ft_strstr(length, "j"))
		return ((void *)va_arg(ap, intmax_t *));
	else if (ft_strstr(length, "ll"))
		return ((void *)va_arg(ap, long long *));
	else if (ft_strstr(length, "l"))
		return ((void *)va_arg(ap, long *));
	else if (ft_strstr(length, "hh"))
		return ((void *)va_arg(ap, signed char *));
	else if (ft_strstr(length, "h"))
		return ((void *)va_arg(ap, short *));
	exit(EXIT_FAILURE);
}
