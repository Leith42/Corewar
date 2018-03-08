/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:37:43 by mmatime           #+#    #+#             */
/*   Updated: 2016/11/21 13:55:58 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*allnodes;
	t_list	*next;

	allnodes = *alst;
	while (allnodes)
	{
		next = allnodes->next;
		del(allnodes->content, allnodes->content_size);
		free(allnodes);
		allnodes = next;
	}
	*alst = NULL;
}
