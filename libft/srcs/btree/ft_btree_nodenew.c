/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_nodenew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:34:39 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 04:24:01 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_btree		*ft_btree_nodenew(void *data)
{
	t_btree		*node;

	node = (t_btree*)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->right = NULL;
	node->left = NULL;
	node->data = data;
	return (node);
}
