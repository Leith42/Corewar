/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:21:49 by lmartin-          #+#    #+#             */
/*   Updated: 2018/02/15 18:21:50 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		write(1, "Usage: ./asm File_Name\n", 23);
	else if (!(ft_strnequ(av[1] + ft_strlen(av[1]) - 2, ".s", 2)))
		write(1, "Wrong file\n", 11);
	else if (!(fd = open(av[1], O_RDONLY)))
	 	write(1, "Wrong file\n", 11);
	return (0);
}
