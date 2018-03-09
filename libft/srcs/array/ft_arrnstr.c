/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 05:40:21 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 05:40:56 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrnstr(char **arr, char *str, size_t n)
{
	while (*arr)
	{
		if (ft_strnequ(*arr, str, n))
			return (*arr);
		arr++;
	}
	return (NULL);
}
