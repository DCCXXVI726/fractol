/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:46:50 by thorker           #+#    #+#             */
/*   Updated: 2019/03/25 18:23:01 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_kernel_arg(t_frac *frac)
{
	frac->error |= clSetKernelArg(frac->kernel, 0, sizeof(cl_mem),
			&(frac->memobj));
	frac->error |= clSetKernelArg(frac->kernel, 1, sizeof(double), &(frac->x0));
	frac->error |= clSetKernelArg(frac->kernel, 2, sizeof(double), &(frac->y0));
	frac->error |= clSetKernelArg(frac->kernel, 3, sizeof(double), &(frac->x1));
	frac->error |= clSetKernelArg(frac->kernel, 4, sizeof(double), &(frac->y1));
	frac->error |= clSetKernelArg(frac->kernel, 5, sizeof(int),
			&(frac->max_iter));
	frac->error |= clSetKernelArg(frac->kernel, 6, sizeof(char), &(frac->type));
	frac->error |= clSetKernelArg(frac->kernel, 7, sizeof(int), &(frac->color));
	frac->error |= clSetKernelArg(frac->kernel, 8, sizeof(double),
			&(frac->c_re));
	frac->error |= clSetKernelArg(frac->kernel, 9, sizeof(double),
			&(frac->c_im));
	frac->error |= clSetKernelArg(frac->kernel, 10, sizeof(int),
			&(frac->shift));
	if (frac->error != CL_SUCCESS)
		put_error_n_exit("SetKernelArg problem");
}

int			fill_color(t_frac *frac)
{
	char *string;

	string = ft_strnew(frac->limit * sizeof(int));
	set_kernel_arg(frac);
	frac->error = clEnqueueNDRangeKernel(frac->command_queue, frac->kernel,
			1, 0, &(frac->limit), 0, 0, 0, 0);
	if (frac->error != CL_SUCCESS)
		put_error_n_exit("EnqueueNDRangeKernel problem");
	frac->error = clEnqueueReadBuffer(frac->command_queue, frac->memobj,
			CL_TRUE, 0, frac->limit * sizeof(int), string, 0, 0, 0);
	ft_memcpy(frac->start_img, string, frac->limit * sizeof(int));
	free (string);
	return (0);
}

void		put_img(t_frac *frac)
{
	fill_color(frac);
	put_interface(frac);
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr, 0, 0);
}
