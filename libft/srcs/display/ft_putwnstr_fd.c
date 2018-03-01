/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:39:34 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/06 19:39:57 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwnstr_fd(wchar_t *ws, size_t len, int fd)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_putwchar_fd(ws[i], fd);
		i++;
	}
}
