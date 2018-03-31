/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 05:27:27 by gudemare          #+#    #+#             */
/*   Updated: 2018/03/29 17:42:09 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_free_arr(char **ar)
{
	size_t	i;

	if (!ar)
		return (0);
	i = 0;
	while (ar[i])
		ft_strdel((ar + i++));
	free(ar);
	return (1);
}
