/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:46:21 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/17 19:57:14 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(join = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
													ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + ft_strlen(s1)), s2);
	return (join);
}
