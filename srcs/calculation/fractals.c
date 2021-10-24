/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:36:23 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 11:54:47 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_bubble(t_fractol *fractol, int x, int y)
{
	int			i;
	t_complex	z;
	double		tmp;

	i = 0;
	z = ft_get_complex(fractol, x, y);
	while ((z.imagin * z.imagin) <= 4
		&& i < fractol->max_iter)
	{
		tmp = z.real * z.real - z.imagin * z.imagin + fractol->c.real;
		z.imagin = 2 * z.real * z.imagin + fractol->c.imagin;
		z.real = tmp;
		i++;
	}
	ft_pixel(ft_new_color(i, fractol), x, y);
}

void	ft_burning_ship(t_fractol *fractol, int x, int y)
{
	int			i;
	t_complex	z[2];
	double		tmp;

	i = 0;
	z[0] = ft_get_complex(fractol, x, y);
	z[1] = ft_get_complex(fractol, x, y);
	while (z[0].real * z[0].real + z[0].imagin * z[0].imagin <= 4
		&& i < fractol->max_iter)
	{
		tmp = (z[0].real * z[0].real - z[0].imagin * z[0].imagin) + z[1].real;
		z[0].imagin = -2.0 * ft_abs_double(z[0].real * z[0].imagin)
			+ z[1].imagin;
		z[0].real = tmp;
		i++;
	}
	ft_pixel(ft_new_color(i, fractol), x, y);
}

void	ft_tunnel(t_fractol *fractol, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	opt_z;

	z = ft_get_complex(fractol, x, y);
	opt_z.real = z.real * z.real;
	opt_z.imagin = z.imagin * z.imagin;
	i = 0;
	while (opt_z.imagin + opt_z.imagin <= 4 && i < fractol->max_iter)
	{
		z.imagin = z.real * z.imagin;
		z.imagin += z.imagin + z.imagin;
		z.imagin += fractol->c.imagin;
		z.real = opt_z.real - opt_z.imagin + fractol->c.real;
		opt_z.real = z.real * z.real;
		opt_z.imagin = z.imagin * z.imagin;
		i++;
	}
	ft_pixel(ft_new_color(i, fractol), x, y);
}
