/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:04:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/16 00:43:44 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_spec
{
	char			*format;
	int				min_width;
	int				precision;
	char			*length;
	char			conv;
}					t_spec;

typedef	int			(*t_conv_ptr)(va_list ap, t_spec spec, int fd);

int					conv_c(va_list ap, t_spec spec, int fd);
int					conv_d(va_list ap, t_spec spec, int fd);
int					conv_o(va_list ap, t_spec spec, int fd);
int					conv_p(va_list ap, t_spec spec, int fd);
int					conv_s(va_list ap, t_spec spec, int fd);
int					conv_u(va_list ap, t_spec spec, int fd);
int					conv_x(va_list ap, t_spec spec, int fd);

t_conv_ptr			*fill_conv_list(void);
int					handle_conv(const t_conv_ptr *conv_list,
		const char *restrict *str, va_list ap, int fd);
int					fill_spec(const char *restrict str,
						t_spec *spec, va_list ap);
long long			get_di_arg(va_list ap, char *length);
unsigned long long	get_oux_arg(va_list ap, char *length);
void				*get_n_arg(va_list ap, char *length);

char				*ft_anytoa(long long n);
char				*ft_uanytoa(unsigned long long n);
char				*ft_uanytoa_base(unsigned long long n, int base);

#endif
