/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:41:43 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 22:44:36 by thorker          ###   ########.fr       */
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
		if (frac->color / 256 / 256 > 0)
			frac->color = frac->color - 256 * 256;
	if (key == 5)
		if (frac->color / 256 % 256 < 255)
			frac->color = frac->color + 256;
	if (key == 4)
		if (frac->color / 256 % 256 > 0)
			frac->color = frac->color - 256;
	if (key == 11)
		if (frac->color % 256 < 255)
			frac->color = frac->color + 1;
	if (key == 45)
		if (frac->color % 256 > 0)
			frac->color = frac->color - 1;
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
	i = (frac->y0 - frac->y1) / 20;
	if (key == 126)
	{
		frac->y0 = frac->y0 - i;
		frac->y1 = frac->y1 - i;
	}
	if (key == 125)
	{
		frac->y0 = frac->y0 + i;
		frac->y1 = frac->y1 + i;
	}
}
