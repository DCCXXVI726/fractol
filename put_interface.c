/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:09:52 by thorker           #+#    #+#             */
/*   Updated: 2019/03/25 18:20:56 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_interface4(t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1000, 300, 0xFFFFFF,
			"ZOOM : + -");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1000, 330, 0xFFFFFF,
			"MAX ITER: pg_");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1000, 360, 0xFFFFFF,
			"MOVE: arrow");
	if (frac->type == 'S')
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
}

void	put_interface3(t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 220, 0xFFFFFF,
			"^     ^     ^");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 220, 0xFFFFFF,
			"|     |     |");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 245, 0xFFFFFF,
			"v     v     v");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 240, 0xFFFFFF,
			"|     |     |");
	if (frac->cpu_gpu == CL_DEVICE_TYPE_GPU)
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 270, 0x0000FF,
				"GPU");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 270, 0xFFFFFF,
				"GPU");
	if (frac->cpu_gpu == CL_DEVICE_TYPE_CPU)
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1095, 270, 0x0000FF,
				"CPU");
	else
		mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1095, 270, 0xFFFFFF,
				"CPU");
	put_interface4(frac);
}

void	put_interface2(t_frac *frac)
{
	char	*c;

	c = ft_itoa(frac->max_iter);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1090, 130, 0xFFFFFF,
			c);
	free(c);
	c = ft_itoa(frac->color / 256 / 256);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 200, 0xFFFFFF,
			c);
	free(c);
	c = ft_itoa(frac->color / 256 % 256);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1095, 200, 0xFFFFFF,
			c);
	free(c);
	c = ft_itoa(frac->color % 256);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1155, 200, 0xFFFFFF,
			c);
	free(c);
	put_interface3(frac);
}

void	put_interface(t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1000, 160, 0xFFFFFF,
			"COLOR:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1035, 180, 0xFFFFFF,
			"R     G     B");
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
	put_interface2(frac);
}
