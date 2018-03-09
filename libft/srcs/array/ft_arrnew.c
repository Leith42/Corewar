/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 04:58:07 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 12:09:55 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_arrnew(size_t size)
{
	char	**array;

	if (!(array = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (size > 0)
		array[size--] = NULL;
	*array = NULL;
	return (array);
}
