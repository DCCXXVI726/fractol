/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:33:29 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 23:19:30 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_img(t_frac *frac, int key, void (*f)(t_frac *, int))
{
	f(frac, key);
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	put_img(frac);
}

int		key_press(int key, t_frac *frac)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		change_img(frac, key, move);
	if (key == 53)
		exit(1);
	if (key == 69 || key == 78)
		change_img(frac, key, scale);
	if (key == 116 || key == 121)
		change_img(frac, key, change_iter);
	if (key == 15 || key == 17 || key == 5 || key == 4 || key == 11
			|| key == 45)
		change_img(frac, key, change_color);
	if (key == 92 || key == 88)
		change_img(frac, key, shift_color);
	if (key == 49)
	{
		set_start_arg(frac);
		mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
		put_img(frac);
	}
	if (key == 0 || key == 1)
		change_img(frac, key, change_cpu_gpu);
	return (0);
}

int		ft_mouse_move(int x, int y, t_frac *frac)
{
	if (frac->type == 'J' && frac->flag == 1 && x >= 0 &&
			x <= 1000 && y >= 0 && y <= 1000)
	{
		frac->c_re = ((double)x - 500) / 1000;
		frac->c_im = ((double)y - 500) / 1000;
		mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
		put_img(frac);
	}
	return (0);
}

int		ft_close(t_frac *frac)
{
	(void)frac;
	exit(0);
	return (0);
}

int		hook(t_frac *frac)
{
	mlx_hook(frac->win_ptr, 4, 0, mouse_click, frac);
	mlx_hook(frac->win_ptr, 2, 0, key_press, frac);
	mlx_hook(frac->win_ptr, 6, 0, ft_mouse_move, frac);
	mlx_hook(frac->win_ptr, 17, 9, ft_close, frac);
	return (0);
}
