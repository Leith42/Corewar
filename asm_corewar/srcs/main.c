/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:21:49 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/05 03:47:24 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		ft_putstr("Usage: ./asm File_Name\n");
	else if (!(ft_strnequ(av[1] + ft_strlen(av[1]) - 2, ".s", 2)))
		ft_putstr("Error : File is not marked as corewar assembly.\n");
	else if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_putstr("Error : unable to open file.\n");
	else
		ft_read_file(fd, av[1]);
	return (0);
}
