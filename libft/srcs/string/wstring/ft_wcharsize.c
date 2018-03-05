/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:32:37 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/06 19:42:57 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharsize(wchar_t wc)
{
	if (wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 65535)
		return (3);
	else if (wc <= 1114111)
		return (4);
	return (-1);
}
