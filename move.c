/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:41:43 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 13:42:48 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_color(t_frac *frac, int key)
{
	if (key == 92)
		frac->shift = frac->shift + 1;
	if (key == 88)
		frac->shift = frac->shift - 1;
}
void	change_color(t_frac *frac, int key)
{
	if (key == 15)
		if (frac->color / 256 / 256 < 255)
			frac->color = frac->color + 256 * 256;
	if (key == 17)
		if (frac->color / 256 / 256 >1)
			frac->color = frac->color - 256 * 256;
	if (key == 5)
		if (frac->color / 256 % 256 < 255)
			frac->color = frac->color + 256;
	if (key == 4)
		if (frac->color / 256 % 256 >1)
			frac->color = frac->color - 256;
	if (key == 11)
		if (frac->color % 256 < 255)
			frac->color = frac->color + 1;
	if (key == 45)
		if (frac->color % 256 > 1)
			frac->color = frac->color - 1;
}

void	back_start(t_frac *frac, int key)
{
	frac->x0 = START_X0;
	frac->x1 = START_X1;
	frac->y0 = START_Y0;
	frac->y1 = START_Y1;
	frac->max_iter = START_ITER;
	frac->color = START_COLOR;
	if (key == 31)
		frac->type = 'B';
	if (key == 40)
		frac->type = 'N';
	if (key == 46)
		frac->type = 'M';
	if (key == 38)
		frac->type = 'J';
	if (key == 35)
		frac->type = 'P';
}

void	change_iter(t_frac *frac, int key)
{
	if (key == 116)
		frac->max_iter++;
	if (key == 121)
		if (frac->max_iter > 1)
			frac->max_iter--;
}

void	scale(t_frac *frac, int key)
{
	double x;
	double y;

	x = (frac->x1 - frac->x0) / 20;
	y = (frac->y0 - frac->y1) / 20;
	if (key == 69)
	{
		frac->x0 = frac->x0 + x;
		frac->x1 = frac->x1 - x;
		frac->y0 = frac->y0 - y;
		frac->y1 = frac->y1 + y;
	}
	if (key == 78)
	{
		frac->x0 = frac->x0 - x;
		frac->x1 = frac->x1 + x;
		frac->y0 = frac->y0 + y;
		frac->y1 = frac->y1 - y;
	}
}

void	move(t_frac *frac, int key)
{
	double i;

	if (key == 123)
	{
		i = (frac->x1 - frac->x0) / 20;
		frac->x0 = frac->x0 - i;
		frac->x1 = frac->x1 - i;
	}
	if (key == 124)
	{
        i = (frac->x1 - frac->x0) / 20;
		frac->x0 = frac->x0 + i;
		frac->x1 = frac->x1 + i;
	}
	if (key == 126)
	{
        i = (frac->y0 - frac->y1) / 20;
		frac->y0 = frac->y0 + i;
		frac->y1 = frac->y1 + i;
	}
	if (key == 125)
	{
        i = (frac->y0 - frac->y1) / 20;
		frac->y0 = frac->y0 - i;
		frac->y1 = frac->y1 - i;
	}
}
