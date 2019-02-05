/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:06:38 by thorker           #+#    #+#             */
/*   Updated: 2019/02/05 16:06:30 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
# define WIN_WID 1000
# define WIN_HEI 1000
# include <OpenCL/opencl.h>
# define START_X0 -1
# define START_X1 1
# define START_Y0 1
# define START_Y1 -1
# define START_SHIFT 0
# define START_FLAG 1
# define START_COLOR 0
# define START_ITER 20

typedef struct	s_frac
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*start_img;
	int			bpp;
	int			size_line;
	int			endian;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	cl_device_id	device_id;
	cl_int			error;
	cl_context		context;
	cl_command_queue	command_queue;
	cl_mem				memobj;
	size_t				src_kernel_size;
	char				*src_kernel_str;
	cl_program			program;
	cl_kernel			kernel;
	size_t				limit;
	int					max_iter;
	int					inc_iter;
	char				type;
	int					color;
	double				c_re;
	double				c_im;
	int					flag;
	int					shift;
}				t_frac;
void			set_start_arg(t_frac *frac);
void			put_usage_n_exit();
void			shift_color(t_frac *frac, int key);
void        	change_color(t_frac *frac, int key);
void			back_start(t_frac *frac, int key);
void			change_iter(t_frac *frac, int key);
void			scale(t_frac *frac, int key);
int				hook(t_frac *frac);
void			move(t_frac *frac, int key);
int				init_opencl(t_frac *frac);
void			put_error_n_exit(char *str);
int				fill_color(t_frac *frac);
t_frac			*create_struct(char *name);
void			put_img(t_frac *frac);
void			put_error_n_exit(char *str);
void			put_interface(t_frac *frac);
#endif
