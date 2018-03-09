/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_inplace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 06:26:35 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 03:09:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sorts a char array in-place according to parametered comparison function.
** Uses quicksort algorithm.
*/

#include "libft.h"

void		ft_sort_inplace(
		char **lst, size_t len, int (*ft_cmp)(char *a, char *b))
{
	size_t	lo;
	size_t	hi;

	if (len < 2)
		return ;
	lo = 0;
	hi = --len;
	while (lo < hi)
	{
		while (lo < hi && ft_cmp(lst[lo], lst[len]) <= 0)
			lo++;
		while (lo < hi && ft_cmp(lst[hi], lst[len]) >= 0)
			hi--;
		if (lo != hi)
			ft_swap((void **)&lst[lo], (void **)&lst[hi]);
	}
	ft_swap((void **)&lst[lo], (void **)&lst[len]);
	ft_sort_inplace(lst, lo, ft_cmp);
	ft_sort_inplace(lst + lo + 1, len - lo, ft_cmp);
}
