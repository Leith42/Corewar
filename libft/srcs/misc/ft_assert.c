/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:16:21 by gudemare          #+#    #+#             */
/*   Updated: 2017/08/11 08:06:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"

void	ft_assert(void *ret)
{
	if (!ret)
	{
		ft_dprintf(2, "Fatal error : %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
