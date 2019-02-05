/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:09:52 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 14:23:28 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_interface(t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1000, 0, 0xFFFFFF,
			"NAME:");
	if (frac->type == 'M')
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 20, 0x0000FF,
				"Mandelbrot");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 20, 0xFFFFFF,
				"Mandelbrot");
	if (frac->type == 'J')
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 40, 0x0000FF,
				"Julia");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 40, 0xFFFFFF,
				"Julia");
	if (frac->type == 'N')
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 60, 0x0000FF,
				"Newton");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 60, 0xFFFFFF,
				"Newton");
	if (frac->type == 'P')
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 80, 0x0000FF,
				"Spider");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 80, 0xFFFFFF,
				"Spider");
	if (frac->type == 'B')
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 100, 0x0000FF,
				"Berningship");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1020, 100, 0xFFFFFF,
				"Berningship");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1000, 130, 0xFFFFFF,
			"MAX ITER:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1090, 130, 0xFFFFFF,
			ft_itoa(frac->max_iter));
}
