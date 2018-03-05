/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_lvlcount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 04:38:01 by gudemare          #+#    #+#             */
/*   Updated: 2016/12/06 04:40:53 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_lvlcount(t_btree *root)
{
	if (!root)
		return (1);
	return (ft_max(ft_btree_lvlcount(root->left),
					ft_btree_lvlcount(root->right)));
}
