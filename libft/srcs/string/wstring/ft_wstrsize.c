/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:33:08 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/06 19:33:25 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrsize(wchar_t *ws)
{
	int	ret;

	ret = 0;
	while (*ws)
	{
		ret += ft_wcharsize(*ws);
		ws++;
	}
	return (ret);
}
