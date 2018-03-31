/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:19:27 by lmartin-          #+#    #+#             */
/*   Updated: 2018/03/22 10:07:17 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	header_error(enum e_error error, int line_nb, char *str)
{
	if (error == QUOTE_MARK)
		ft_printf("Can't find quote mark on line %d\n", line_nb);
	else if (error == INVALID_CHAR_NAME)
		ft_printf("Can't write anything without sharp sign ('#') on line %d\n",
		line_nb);
	else if (error == WRONG_INPUT)
		ft_printf("Wrong input on line %d\n", line_nb);
	else if (error == COMMENT_NOT_IN_PLACE)
		ft_printf("Can't comment before %s input on line %d\n", str, line_nb);
	else if (error == NAME_TOO_LONG)
		ft_printf("Champion name too long (Max length 128)\n");
	else if (error == COMMENT_TOO_LONG)
		ft_printf("Champion comment too long (Max length 2048)\n");
	exit(1);
}

int		inst_error(enum e_error error, int line_nb, char *str)
{
	if (error == INVALID_INST)
		ft_printf("Invalid instruction \"%s\" on line %d\n", str, line_nb);
	else if (error == INVALID_PARAMS)
		ft_printf("Invalid parameter on line %d\n", line_nb);
	else if (error == TOO_MANY_PARAMS)
		ft_printf("Too many parameter on line %d\n", line_nb);
	else if (error == WRONG_REGISTER)
		ft_printf("Register can't be \"%s\" on line %d\n", str, line_nb);
	return (0);
}
