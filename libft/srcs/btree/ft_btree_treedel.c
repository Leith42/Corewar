/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_treedel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:28:11 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 04:36:44 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_btree_treedel(t_btree **root, void (*fdel)(void *))
{
	if (!root || !*root)
		return ;
	ft_btree_treedel(&((*root)->left), (*fdel));
	ft_btree_treedel(&((*root)->right), (*fdel));
	(*fdel)((*root)->data);
	free(*root);
}
