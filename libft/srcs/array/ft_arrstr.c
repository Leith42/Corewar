/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 05:38:37 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 05:40:13 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrstr(char **arr, char *str)
{
	while (*arr)
	{
		if (ft_strequ(*arr, str))
			return (*arr);
		arr++;
	}
	return (NULL);
}
