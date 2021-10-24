/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:22:38 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 12:22:41 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_complex	ft_get_complex(t_fractol *fractol, int x, int y)
{
	t_complex	z;

	z.imagin = fractol->max.imagin - y * fractol->radius.imagin;
	z.real = fractol->min.real + x * fractol->radius.real;
	return (z);
}

void	ft_mandelbrot(t_fractol *fractol, int x, int y)
{
	int			i;
	t_complex	z[2];
	t_complex	opt_z;

	i = 0;
	z[0] = ft_get_complex(fractol, x, y);
	z[1] = ft_get_complex(fractol, x, y);
	opt_z.real = z[0].real * z[0].real;
	opt_z.imagin = z[0].imagin * z[0].imagin;
	while (opt_z.real + opt_z.imagin <= 4 && i < fractol->max_iter)
	{
		z[0].imagin = ((z[0].real + z[0].imagin)
				* (z[0].real + z[0].imagin)) - opt_z.real - opt_z.imagin;
		z[0].imagin += z[1].imagin;
		z[0].real = opt_z.real - opt_z.imagin + z[1].real;
		opt_z.real = z[0].real * z[0].real;
		opt_z.imagin = z[0].imagin * z[0].imagin;
		i++;
	}
	ft_pixel(ft_new_color(i, fractol), x, y);
}

void	ft_julia(t_fractol *fractol, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	opt_z;

	z = ft_get_complex(fractol, x, y);
	opt_z.real = z.real * z.real;
	opt_z.imagin = z.imagin * z.imagin;
	i = 0;
	while (opt_z.real + opt_z.imagin <= 4 && i < fractol->max_iter)
	{
		z.imagin = z.real * z.imagin;
		z.imagin += z.imagin;
		z.imagin += fractol->c.imagin;
		z.real = opt_z.real - opt_z.imagin + fractol->c.real;
		opt_z.real = z.real * z.real;
		opt_z.imagin = z.imagin * z.imagin;
		i++;
	}
	ft_pixel(ft_new_color(i, fractol), x, y);
}

int	ft_calculation(t_fractol *fractol, char *argv)
{
	if (!ft_strcmp(argv, "Julia"))
		fractol->func = &ft_julia;
	else if (!ft_strcmp(argv, "Mandelbrot"))
		fractol->func = &ft_mandelbrot;
	else if (!ft_strcmp(argv, "Tunnel"))
		fractol->func = &ft_tunnel;
	 else if (!ft_strcmp(argv, "Bubble"))
		fractol->func = &ft_bubble;
	 else if (!ft_strcmp(argv, "Burning ship"))
		fractol->func = &ft_burning_ship;
	if (!fractol->func)
		return (0);
	else
		return (1);
}
