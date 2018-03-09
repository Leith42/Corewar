/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 02:42:52 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/26 02:51:18 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew_copy(void const *content, size_t content_size)
{
	t_list	*dst;

	if ((dst = (t_list *)malloc(sizeof(*dst))) == NULL)
		return (NULL);
	dst->next = NULL;
	dst->content_size = content_size;
	if (content_size == 0 || !content)
	{
		dst->content = NULL;
		return (dst);
	}
	if (!(dst->content = (void *)malloc(sizeof(char) * content_size)))
	{
		free(dst);
		return (NULL);
	}
	ft_memcpy(dst->content, content, content_size);
	return (dst);
}
