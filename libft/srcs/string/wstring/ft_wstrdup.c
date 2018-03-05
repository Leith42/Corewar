/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:34:38 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/06 19:35:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t *ws)
{
	return ((wchar_t*)ft_memdup(ws, (ft_wstrlen(ws) + 1) * sizeof(wchar_t)));
}
