/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:45:01 by dwulfe            #+#    #+#             */
/*   Updated: 2021/10/24 18:31:11 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_display_menu(t_fractol *f)
{
	ft_bzero(f->img.addr,
		f->w * f->h * (f->img.bits_per_pixel / 8));
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win,
		f->img.img, 0, 0);
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5,
		f->h / 4, 0xc0c0c0, "Controls");
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3),
		0xc0c0c0, "Reset           - R");
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3) * 1.2,
		0xc0c0c0, "Color Shift     - S");
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3) * 1.4,
		0xc0c0c0, "Move            - Arrows");
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3) * 1.6,
		0xc0c0c0, "Zoom            - Scroll");
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3) * 1.8,
		0xc0c0c0, "Iterations      - +/-");
	mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3) * 2.0,
		0xc0c0c0, "Ranges          - C");
		mlx_string_put(f->mlx.ptr, f->mlx.win, (f->w / 4) * 1.5, (f->h / 3) * 2.2,
		0xc0c0c0, "Special colors  - 1 - 9 (hold shift optianal)");
	return (1);
}

int	ft_remove_key(int keycode, t_fractol *fractol)
{
	if (fractol->keys[keycode] == 1)
		fractol->keys[keycode] = 0;
	return (1);
}

int	ft_change_max_iteration(int keycode, t_fractol *fractol)
{
	if (keycode == 78)
		fractol->max_iter -= 1;
	else if (keycode == 27)
		fractol->max_iter -= 10;
	else if (keycode == 69)
		fractol->max_iter += 1;
	else if (keycode == 24)
		fractol->max_iter += 10;
	return (1);
}

int	ft_move(int keycode, t_fractol *fractol)
{
	t_complex	c;

	c.real = ft_abs_double(fractol->max.real - fractol->min.real);
	c.imagin = ft_abs_double(fractol->max.imagin - fractol->min.imagin);
	if (keycode == 124)
	{
		fractol->min.real += c.real * 0.05;
		fractol->max.real += c.real * 0.05;
	}
	else if (keycode == 123)
	{
		fractol->min.real -= c.real * 0.05;
		fractol->max.real -= c.real * 0.05;
	}
	else if (keycode == 125)
	{
		fractol->min.imagin -= c.imagin * 0.05;
		fractol->max.imagin -= c.imagin * 0.05;
	}
	else if (keycode == 126)
	{
		fractol->min.imagin += c.imagin * 0.05;
		fractol->max.imagin += c.imagin * 0.05;
	}
	return (1);
}
