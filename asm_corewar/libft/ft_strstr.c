/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:09:23 by mmatime           #+#    #+#             */
/*   Updated: 2016/11/19 23:11:06 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int temp;

	i = 0;
	temp = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)&big[i]);
	while (big[i])
	{
		j = 0;
		temp = i;
		while (little[j] == big[temp])
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
