/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 05:13:04 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 06:35:14 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree				*ft_btree_search_data(t_btree *root, void *data,
					int (*fcmp)(void *, void *))
{
	if (!root)
		return (NULL);
	if ((*fcmp)(data, root->data) < 0)
		return (ft_btree_search_data(root->left, data, (*fcmp)));
	if ((*fcmp)(data, root->data) > 0)
		return (ft_btree_search_data(root->right, data, (*fcmp)));
	return (root);
}
