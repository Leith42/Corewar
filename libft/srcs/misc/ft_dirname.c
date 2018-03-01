/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:38:53 by gudemare          #+#    #+#             */
/*   Updated: 2016/11/22 03:14:50 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dirname(char *filename)
{
	static const char	dot[] = ".";
	char				*res;

	res = ft_strrchr(filename, '/');
	if (!res)
		return ((char *)dot);
	*res = '\0';
	return (filename);
}
