/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:50:54 by mmatime           #+#    #+#             */
/*   Updated: 2017/12/30 12:57:41 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_custom(char *s1, char *s2, int nb)
{
	char	*temp;
	size_t	len;
	int		index;

	index = 0;
	len = ft_strlen_plus(s1, nb);
	if ((temp = (char *)ft_memalloc(sizeof(char) *
					(len + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	if (s1)
		ft_memcpy(temp, s1, len);
	ft_strcpy(temp + len, s2);
	free((void *)s1);
	return (temp);
}
