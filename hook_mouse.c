/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:21:11 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 22:39:42 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_scroll(int key, int x, int y, t_frac *frac)
{
	double x0;
	double x1;
	double y0;
	double y1;

	x0 = (frac->x1 - frac->x0) * ((double)(x) / 10000);
	x1 = (frac->x1 - frac->x0) * ((double)(1000 - x) / 10000);
	y0 = (frac->y0 - frac->y1) * ((double)(1000 - y) / 10000);
	y1 = (frac->y0 - frac->y1) * ((double)(y) / 10000);
	if (key == 4)
	{
		frac->max_iter = frac->max_iter + frac->iter_ch;
		frac->x0 = frac->x0 + x0;
		frac->x1 = frac->x1 - x1;
		frac->y0 = frac->y0 - y0;
		frac->y1 = frac->y1 + y1;
		return ;
	}
	if (frac->max_iter > 1)
		frac->max_iter = frac->max_iter - frac->iter_ch;
	frac->x0 = frac->x0 - x0;
	frac->x1 = frac->x1 + x1;
	frac->y0 = frac->y0 + y0;
	frac->y1 = frac->y1 - y1;
}

int		start_frac(int x, int y, t_frac *frac)
{
	if (x > 1000 && x <= 1200 && y > 20 && y < 40)
		frac->type = 'M';
	else if (x > 1000 && x <= 1200 && y > 40 && y < 60)
		frac->type = 'J';
	else if (x > 1000 && x <= 1200 && y > 60 && y < 80)
		frac->type = 'N';
	else if (x > 1000 && x <= 1200 && y > 80 && y < 100)
		frac->type = 'S';
	else if (x > 1000 && x <= 1200 && y > 100 && y < 120)
		frac->type = 'B';
	else
		return (0);
	set_start_arg(frac);
	return (1);
}

int		ch_color(int x, int y, t_frac *frac)
{
	if (x >= 1035 && x <= 1045 && y >= 220 && y < 240)
		change_color(frac, 15);
	else if (x >= 1095 && x <= 1105 && y >= 220 && y < 240)
		change_color(frac, 5);
	else if (x >= 1155 && x <= 1165 && y >= 220 && y < 240)
		change_color(frac, 11);
	else if (x >= 1035 && x <= 1045 && y >= 240 && y < 260)
		change_color(frac, 17);
	else if (x >= 1095 && x <= 1105 && y >= 240 && y < 260)
		change_color(frac, 4);
	else if (x >= 1155 && x <= 1165 && y >= 240 && y < 260)
		change_color(frac, 45);
	else
		return (0);
	return (1);
}

void	mouse_left(int x, int y, t_frac *frac)
{
	if (frac->type == 'J' && x <= 1000 && x >= 0 && y <= 1000 && y >= 0)
		frac->flag = frac->flag * (-1);
	if (start_frac(x, y, frac) == 1)
		return ;
	if (ch_color(x, y, frac) == 1)
		return ;
	if (x >= 1035 && x <= 1065 && y >= 270 && y <= 290)
		change_cpu_gpu(frac, 1);
	if (x >= 1095 && x <= 1125 && y >= 270 && y <= 290)
		change_cpu_gpu(frac, 0);
}

int		mouse_click(int key, int x, int y, t_frac *frac)
{
	if ((key == 4 || key == 5) && x >= 0 &&
			x <= WIN_WID && y >= 0 && y <= WIN_HEI)
		ft_mouse_scroll(key, x, y, frac);
	if (key == 1)
		mouse_left(x, y, frac);
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	put_img(frac);
	return (0);
}
