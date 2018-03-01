/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 06:32:20 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 06:34:35 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_btree_apply_infix(t_btree *root,
					void (*fapply)(void *))
{
	if (!root)
		return ;
	ft_btree_apply_infix(root->left, (*fapply));
	(*fapply)(root->data);
	ft_btree_apply_infix(root->right, (*fapply));
}
