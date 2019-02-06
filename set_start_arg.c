/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:39:22 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 23:33:28 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_start_arg3(t_frac *frac)
{
	if (frac->type == 'S')
	{
		frac->x0 = -2;
		frac->y0 = 2;
		frac->x1 = 2;
		frac->y1 = -2;
		frac->max_iter = 80;
		frac->iter_ch = 1;
	}
	if (frac->type == 'N')
	{
		frac->x0 = -100;
		frac->y0 = 100;
		frac->x1 = 100;
		frac->y1 = -100;
		frac->max_iter = 40;
		frac->iter_ch = 1;
	}
}

void	set_start_arg2(t_frac *frac)
{
	if (frac->type == 'J')
	{
		frac->x0 = -1.5;
		frac->y0 = 1.5;
		frac->x1 = 1.5;
		frac->y1 = -1.5;
		frac->max_iter = 50;
		frac->iter_ch = 2;
		frac->flag = 1;
	}
	if (frac->type == 'B')
	{
		frac->x0 = -2.5;
		frac->y0 = 2.5;
		frac->x1 = 2.5;
		frac->y1 = -2.5;
		frac->max_iter = 40;
		frac->iter_ch = 2;
	}
	set_start_arg3(frac);
}

void	set_start_arg(t_frac *frac)
{
	frac->color = 0;
	frac->shift = 0;
	frac->flag = 1;
	if (frac->type == 'M')
	{
		frac->x0 = -2;
		frac->y0 = 2;
		frac->x1 = 2;
		frac->y1 = -2;
		frac->max_iter = 20;
		frac->iter_ch = 2;
	}
	set_start_arg2(frac);
}
