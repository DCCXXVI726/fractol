/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:33:29 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 13:42:34 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_img(t_frac *frac, int key, void (*f)(t_frac *, int))
{
	f(frac, key);
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	put_img(frac);
}

int	mouse_scroll(int key, int x, int y, t_frac *frac)
{
	double x0;
	double x1;
	double y0;
	double y1;

	x0 = (frac->x1 - frac->x0) * ((double)(x) / 10000);
	x1 = (frac->x1 - frac->x0) * ((double)(1000 - x) / 10000);
	y0 = (frac->y0 - frac->y1) * ((double)(1000 - y) / 10000);
	y1 = (frac->y0 - frac->y1) * ((double)(y) / 10000);
	if (key == 1)
	{
		frac->flag = frac->flag * (-1);
		return (0);
	}
	if (key == 4 && x >=0 && x <= WIN_WID && y >= 0 && y <= WIN_HEI)
	{
		frac->max_iter = frac->max_iter + 2;
		frac->x0 = frac->x0 + x0;
		frac->x1 = frac->x1 - x1;
		frac->y0 = frac->y0 - y0;
		frac->y1 = frac->y1 + y1;
	}
	else if (key == 5 && x >=0 && x <= WIN_WID && y >= 0 && y <= WIN_HEI)
	{
		frac->max_iter = frac->max_iter - 2;
		frac->x0 = frac->x0 - x0;
		frac->x1 = frac->x1 + x1;
		frac->y0 = frac->y0 + y0;
		frac->y1 = frac->y1 - y1;
	}
	else
		return (0);
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	put_img(frac);
	return (0);
}

int	mouse_move(int x, int y, t_frac *frac)
{
	if (frac->type == 'J' && frac->flag == 1)
	{
		frac->c_re = ((double)x - 500) / 1000;
		frac->c_im = ((double)y - 500) / 1000;
		mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
		put_img(frac);
	}
	return (0);
}

int	key_press(int key, t_frac *frac)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		change_img(frac, key, move);
	if (key == 53)
		exit(1);
	if (key == 69 || key == 78)
		change_img(frac, key, scale);
	if (key == 116 || key == 121)
		change_img(frac, key, change_iter);
	if (key == 49 || key == 38 || key == 46 || key == 40 || key == 35 || key == 31)
		change_img(frac, key, back_start);
	if (key == 15 || key == 17 || key == 5 || key == 4 || key == 11 || key == 45)
		change_img(frac, key, change_color);
	if (key == 92 || key == 88)
		change_img(frac, key, shift_color);
	return (0);
}

int	hook(t_frac *frac)
{
	mlx_hook(frac->win_ptr, 4, 0, mouse_scroll, frac);
	mlx_hook(frac->win_ptr, 2, 0, key_press, frac);
	mlx_hook(frac->win_ptr, 6, 0, mouse_move, frac);
	return (0);
}
