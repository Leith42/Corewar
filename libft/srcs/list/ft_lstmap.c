/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:31:17 by gudemare          #+#    #+#             */
/*   Updated: 2017/02/06 18:38:43 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;
	t_list	*new;
	t_list	*tmp;

	dst = f(lst);
	new = dst;
	while (lst->next && new)
	{
		lst = lst->next;
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		new = new->next;
	}
	return (dst);
}
