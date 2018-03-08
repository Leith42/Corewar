/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:20:40 by mmatime           #+#    #+#             */
/*   Updated: 2016/11/21 21:17:29 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *new;
	t_list *tmp;

	newlist = NULL;
	if (f && lst)
	{
		new = f(lst);
		if ((newlist = ft_lstnew(new->content, new->content_size)))
		{
			tmp = newlist;
			lst = lst->next;
			while (lst)
			{
				new = f(lst);
				if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
					return (NULL);
				tmp = tmp->next;
				lst = lst->next;
			}
		}
	}
	return (newlist);
}
