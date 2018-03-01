/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:03:23 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 02:45:18 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*dst;

	if ((dst = (t_list *)malloc(sizeof(*dst))) == NULL)
		return (NULL);
	dst->next = NULL;
	dst->content_size = content_size;
	dst->content = (void *)content;
	return (dst);
}
