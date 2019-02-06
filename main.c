/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:24:17 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 23:06:46 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_frac	*frac;

	if (ac != 2)
		put_usage_n_exit();
	if ((frac = create_struct(av[1])) == 0)
		return (0);
	init_opencl(frac);
	put_img(frac);
	hook(frac);
	mlx_loop(frac->mlx_ptr);
}
