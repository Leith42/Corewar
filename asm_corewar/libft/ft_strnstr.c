/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:27:31 by mmatime           #+#    #+#             */
/*   Updated: 2016/11/19 23:06:00 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	size_t	temp;

	i = 0;
	temp = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)&big[i]);
	while (big[i])
	{
		j = 0;
		temp = i;
		while (little[j] == big[temp] && temp < len)
		{
			temp++;
			j++;
			if (little[j] == '\0')
				return ((char*)&big[i]);
		}
		i++;
	}
	return (NULL);
}
