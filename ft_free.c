/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:04:39 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 20:42:00 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_finishopencl(t_frac *frac)
{
	if (frac->command_queue != 0)
	{
		if ((frac->error = clFlush(frac->command_queue)) != CL_SUCCESS)
			put_error_n_exit("Flush problem");
		if ((frac->error = clFinish(frac->command_queue)) != CL_SUCCESS)
			put_error_n_exit("Finish problem");
		if ((frac->error = clReleaseCommandQueue(frac->command_queue)) != 0)
			put_error_n_exit("ReleaseCommndQueue problem");
	}
	if (frac->kernel != 0)
		if ((frac->error = clReleaseKernel(frac->kernel)) != 0)
			put_error_n_exit("ReleaseKernel problem");
	if (frac->program != 0)
		if ((frac->error = clReleaseProgram(frac->program)) != 0)
			put_error_n_exit("ReleaseProgram problem");
	if (frac->memobj != 0)
		if ((frac->error = clReleaseMemObject(frac->memobj)) != 0)
			put_error_n_exit("ReleaseMemObject problem");
	if (frac->context != 0)
		if ((frac->error = clReleaseContext(frac->context)) != 0)
			put_error_n_exit("ReleaseContext problem");
}
