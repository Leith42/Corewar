/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgraham <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 02:31:03 by lgraham           #+#    #+#             */
/*   Updated: 2018/03/19 02:54:50 by lgraham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		calc_dist_label(t_label *label)
{
	t_label		*dec;
	t_label		*app;

	dec = label;
	app = label;
	while (app->next != NULL)
	{
		if (app->type > 0)
		{
			while (dec->next != NULL && (ft_strcmp(app->name, dec->name) || \
					dec->type > 0))
				dec = dec->next;
			if (ft_strcmp(app->name, dec->name) && dec->type > 0)
				app->res = (dec->oct + MEM_SIZE - app->oct) % MEM_SIZE;
		}
		app = app->next;
		dec = label;
	}
}
