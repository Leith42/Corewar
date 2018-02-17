/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:44:16 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/10 18:38:39 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int l;
	int i;

	l = 0;
	i = 0;
	if (!little[i])
		return (char *)(big);
	while (big[i])
	{
		if (big[i] == little[l])
		{
			while (big[i + l] == little[l] && big[i + l])
				l++;
			if (!little[l])
				return (char *)(&big[i]);
			l = 0;
		}
		i++;
	}
	return (0);
}
