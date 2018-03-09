/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 06:27:48 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 06:34:35 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_btree_apply_prefix(t_btree *root,
					void (*fapply)(void *))
{
	if (!root)
		return ;
	(*fapply)(root->data);
	ft_btree_apply_prefix(root->left, (*fapply));
	ft_btree_apply_prefix(root->right, (*fapply));
}
