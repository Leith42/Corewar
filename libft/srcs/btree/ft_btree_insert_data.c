/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 05:12:15 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 05:30:16 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *data,
		int (*fcmp)(void *, void *))
{
	if (!root)
		return ;
	else if (!*root)
		*root = ft_btree_nodenew(data);
	else if ((*fcmp)(data, (*root)->data) <= 0)
		ft_btree_insert_data(&((*root)->left), data, (*fcmp));
	else if ((*fcmp)(data, (*root)->data) > 0)
		ft_btree_insert_data(&((*root)->right), data, (*fcmp));
}
