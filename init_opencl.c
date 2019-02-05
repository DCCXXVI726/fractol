/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:00:09 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 15:42:17 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char    *load_kernel(t_frac *frac)
{
    int fd;
    char *line;
    char *tmp;
    char *old_tmp;
    int gnl;
    
    tmp = ft_strnew(0);
    if ((fd = open("hello.cl",O_RDONLY)) < 0)
        put_error_n_exit("Didn't open file");
    while ((gnl = get_next_line(fd, &line)) != 0)
    {
        if (gnl < 0)
            put_error_n_exit("Didn't read file");
        old_tmp = tmp;
        tmp = ft_strjoin(old_tmp, "\n");
        free(old_tmp);
        old_tmp = tmp;
        tmp = ft_strjoin(old_tmp, line);
        free(line);
        free(old_tmp);
    }
    if (ft_strlen(tmp) != 0)
    {
        old_tmp = tmp;
        tmp = ft_strjoin(old_tmp, "\n");
        free(old_tmp);
        free(line);
    }
    else
        ft_strdel(&tmp);
    return (tmp);
}

int	init_opencl(t_frac *frac)
{
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    
    frac->src_kernel_str = load_kernel(frac);
    frac->src_kernel_size = ft_strlen(frac->src_kernel_str);
    
    frac->error = clGetDeviceIDs(0, CL_DEVICE_TYPE_GPU, 1, &(frac->device_id), 0);
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("GetDeviceIDS problem");
    frac->context = clCreateContext(0, 1, &(frac->device_id), 0, 0, &(frac->error));
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("CreateContext problem");
    frac->command_queue = clCreateCommandQueue(frac->context, frac->device_id, 0, &(frac->error));
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("CreateCommandQueue problem");
    frac->memobj = clCreateBuffer(frac->context, CL_MEM_WRITE_ONLY, WIN_HEI * WIN_WID * sizeof(int), NULL, &(frac->error));
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("CreateBuffer problem");
    frac->program = clCreateProgramWithSource(frac->context, 1, (const char **)&(frac->src_kernel_str),
                                              (const size_t *)&(frac->src_kernel_size), &(frac->error));
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("CreateProgramWithSource problem");
    frac->error = clBuildProgram(frac->program, 0, 0, 0, 0, 0);
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("BuildProgram problem");
    frac->kernel = clCreateKernel(frac->program, "hello", &(frac->error));
    if (frac->error != CL_SUCCESS)
        put_error_n_exit("CreateKernel problem");
	return (0);
}
