/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:40:09 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 11:54:36 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_draw(t_fractol *fractol)
{
	int	y;
	int	x;

	fractol->radius.real = (fractol->max.real - fractol->min.real)
		/ (fractol->w - 1);
	fractol->radius.imagin = (fractol->max.imagin - fractol->min.imagin)
		/ (fractol->h - 1);
	if (fractol->func == ft_bubble)
		ft_new_pallete(fractol);
	y = -1;
	while (++y < fractol->h)
	{
		x = -1;
		while (++x < fractol->w)
			fractol->func(fractol, x, y);
	}
	mlx_put_image_to_window(fractol->mlx.ptr, fractol->mlx.win,
		fractol->img.img, 0, 0);
}

int	ft_color_gen(float start, double t, int degree, int reg)
{
	if (reg == 0)
		return ((int)(start * (1 - t) * pow(t, degree) * 255));
	else if (reg == 1)
		return ((int)(start * pow((1 - t), degree) * pow(t, degree) * 255));
	else
		return ((int)(start * pow((1 - t), degree) * t * 255));
}

t_fractol	*ft_new_color(int iteration, t_fractol *fractol)
{
	double	t;

	t = (double)iteration / fractol->max_iter;
	fractol->color.t = 0;
	fractol->color.r = ft_color_gen(fractol->transformation.c_arr[0][0],
			t, fractol->transformation.c_arr[0][1],
			fractol->transformation.c_arr[0][2]);
	fractol->color.g = ft_color_gen(fractol->transformation.c_arr[1][0],
			t, fractol->transformation.c_arr[1][1],
			fractol->transformation.c_arr[1][2]);
	fractol->color.b = ft_color_gen(fractol->transformation.c_arr[2][0],
			t, fractol->transformation.c_arr[2][1],
			fractol->transformation.c_arr[2][2]);
	return (fractol);
}

void	ft_pixel(t_fractol *fractol, int x, int y)
{
	int	i;

	i = (x * fractol->img.bits_per_pixel / 8) + (y * fractol->img.line_length);
	fractol->img.addr[i] = fractol->color.b;
	fractol->img.addr[++i] = fractol->color.g;
	fractol->img.addr[++i] = fractol->color.r;
	fractol->img.addr[++i] = fractol->color.t;
}
