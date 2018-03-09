/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:50:45 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 02:32:23 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Direct output is used if ft_itoa fails (for malloc reasons).
*/

void	ft_putnbr_fd(int nb, int fd)
{
	char	*res;

	if ((res = ft_itoa(nb)))
	{
		ft_putstr_fd(res, fd);
		ft_strdel(&res);
		return ;
	}
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
