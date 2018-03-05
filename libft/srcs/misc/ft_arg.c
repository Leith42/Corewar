/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:55:46 by gudemare          #+#    #+#             */
/*   Updated: 2017/04/13 17:00:59 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arg(int argc, int min_argc, int max_argc, char *usage)
{
	if (argc >= min_argc && argc <= max_argc)
		return (1);
	ft_putstr_fd(usage, 2);
	return (0);
}
