/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:26:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/27 19:41:54 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnendl_fd(char const *s, int fd, size_t n)
{
	write(fd, s, ft_min_pos(ft_strlen(s), n));
	write(fd, "\n", 1);
}
