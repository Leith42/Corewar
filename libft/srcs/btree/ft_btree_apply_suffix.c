/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 06:32:15 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 06:34:35 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_btree_apply_suffix(t_btree *root,
					void (*fapply)(void *))
{
	if (!root)
		return ;
	ft_btree_apply_suffix(root->left, (*fapply));
	ft_btree_apply_suffix(root->right, (*fapply));
	(*fapply)(root->data);
}
