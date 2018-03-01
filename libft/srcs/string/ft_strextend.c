/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:03:05 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:46:30 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strextend(char *str, size_t size)
{
	char	*new;

	if (!(new = ft_strnew(ft_strlen(str) + size)))
		return (NULL);
	ft_strcpy(new, str);
	free(str);
	return (new);
}
