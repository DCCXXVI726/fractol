/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_smth_n_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:07:15 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 23:10:25 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_usage_n_exit(void)
{
	ft_putstr("usage: FractalName\nPossible fractal:\n");
	ft_putstr("\tMandelbrot\n\tJulia\n\tBerningship\n\tSpider\n\tNewton");
	exit(0);
}

void	put_error_n_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}
