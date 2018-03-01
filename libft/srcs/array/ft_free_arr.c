/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 05:27:27 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/28 22:36:50 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_free_arr(char **ar)
{
	size_t	i;

	if (!ar)
		return ;
	i = 0;
	while (ar[i])
		ft_strdel((ar + i++));
	free(ar);
}
