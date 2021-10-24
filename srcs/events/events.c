/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:03:56 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 11:54:19 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_reload(t_fractol *fractol)
{
	ft_default(fractol);
	return (1);
}

int	ft_shift_color(int keycode, t_fractol *fractol)
{
	if (fractol->keys[keycode] == 0)
	{
		fractol->keys[keycode] = 1;
		if (keycode == 1)
			return (ft_switch_set(fractol));
		else if (keycode == 18)
			return (ft_change_colorset(fractol, 0, 0, fractol->keys[257]));
		else if (keycode == 19)
			return (ft_change_colorset(fractol, 0, 1, fractol->keys[257]));
		else if (keycode == 20)
			return (ft_change_colorset(fractol, 0, 2, fractol->keys[257]));
		else if (keycode == 21)
			return (ft_change_colorset(fractol, 1, 0, fractol->keys[257]));
		else if (keycode == 23)
			return (ft_change_colorset(fractol, 1, 1, fractol->keys[257]));
		else if (keycode == 22)
			return (ft_change_colorset(fractol, 1, 2, fractol->keys[257]));
		else if (keycode == 26)
			return (ft_change_colorset(fractol, 2, 0, fractol->keys[257]));
		else if (keycode == 28)
			return (ft_change_colorset(fractol, 2, 1, fractol->keys[257]));
		else if (keycode == 25)
			return (ft_change_colorset(fractol, 2, 2, fractol->keys[257]));
	}
	return (0);
}

int	ft_handler_an_key(int keycode, t_fractol *fractol)
{
	if (keycode == 8)
		return (ft_new_range(fractol));
	if (keycode == 15)
		return (ft_reload(fractol));
	else if (keycode == 27 || keycode == 24
		|| keycode == 78 || keycode == 69)
		return (ft_change_max_iteration(keycode, fractol));
	else if (keycode == 124 || keycode == 125
		|| keycode == 123 || keycode == 126)
		return (ft_move(keycode, fractol));
	else
		return (ft_shift_color(keycode, fractol));
}

int	ft_handle_key(int keycode, t_fractol *fractol)
{
	if (fractol->keys[keycode] == 0)
	{
		if (keycode == 53)
			exit(EXIT_SUCCESS);
		else if (keycode == 46)
		{
			fractol->keys[keycode] = 1;
			fractol->is_changed = 1;
			if (!fractol->menu)
				fractol->menu = 1;
			else
				fractol->menu = 0;
		}
		else if (!fractol->menu)
			fractol->is_changed = ft_handler_an_key(keycode, fractol);
	}
	return (1);
}

int	ft_zoom(int keycode, int x, int y, t_fractol *fractol)
{
	t_complex	tmp;

	if (!fractol->is_changed && !fractol->menu)
	{
		tmp.real = (double)x / (fractol->w / (fractol->max.real
					- fractol->min.real)) + fractol->min.real;
		tmp.imagin = (double)y / (fractol->h / (fractol->max.imagin
					- fractol->min.imagin)) * -1 + fractol->max.imagin;
		if (keycode == 4)
			fractol->transformation.zoom = 0.80;
		else if (keycode == 5)
			fractol->transformation.zoom = 1.20;
		fractol->min.real = tmp.real + ((fractol->min.real - tmp.real) * 1
				/ fractol->transformation.zoom);
		fractol->min.imagin = tmp.imagin + ((fractol->min.imagin - tmp.imagin)
				* 1 / fractol->transformation.zoom);
		fractol->max.real = tmp.real + ((fractol->max.real - tmp.real) * 1
				/ fractol->transformation.zoom);
		fractol->max.imagin = tmp.imagin + ((fractol->max.imagin - tmp.imagin)
				* 1 / fractol->transformation.zoom);
		fractol->is_changed = 1;
	}
	return (1);
}
