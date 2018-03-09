/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 10:13:56 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/11 11:18:33 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strextjoin(char *s1, char const *s2)
{
	if (!(s1 = ft_strextend(s1, ft_strlen(s2))))
		return (NULL);
	ft_strcat(s1, s2);
	return (s1);
}
