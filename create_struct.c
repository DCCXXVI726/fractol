/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:27:56 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 15:48:04 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx(t_frac *new)
{
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, WIN_WID + 200, WIN_HEI, "Fractol");
	new->img_ptr = mlx_new_image(new->mlx_ptr, WIN_WID, WIN_HEI);
	new->start_img = mlx_get_data_addr(new->img_ptr, &(new->bpp), &(new->size_line), &(new->endian));
	new->bpp = new->bpp / 8;
}

static int	choose_frac(t_frac *new, char *str)
{
	int i;
	
	i = -1;
	while (*(str + (++i)) != 0)
		*(str + i) = ft_tolower(*(str + i));
	if (ft_strcmp(str, "mandelbrot") == 0)
		new->type = 'M';
	else if (ft_strcmp(str, "julia") == 0)
		new->type = 'J';
	else if (ft_strcmp(str, "berningship") == 0)
		new->type = 'B';
	else if (ft_strcmp(str, "spider") == 0)
		new->type = 'S';
	else if (ft_strcmp(str, "newton") == 0)
		new->type = 'N';
	else
		return (0);
	return (1);
}

t_frac	*create_struct(char *str)
{
	t_frac	*new;

	if ((new = (t_frac*)malloc(sizeof(t_frac))) == 0)
		return (0);
	if (choose_frac(new, str) == 0)
	{
		free(new);
		put_usage_n_exit();
	}
	init_mlx(new);
	set_start_arg(new);
	new->x0 = START_X0;
	new->y0 = START_Y0;
	new->x1 = START_X1;
	new->y1 = START_Y1;
	new->context = 0;
	new->command_queue = 0;
	new->limit = WIN_WID * WIN_HEI;
	new->max_iter = START_ITER;
	new->color = START_COLOR;
	new->flag = START_FLAG;
	new->shift = START_SHIFT;
	return (new);
}
