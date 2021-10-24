/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:22:49 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 12:22:50 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	ft_abs_double(double num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	ft_exit(int keycode)
{
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_new_range(t_fractol *fractol)
{
	fractol->current_range++;
	if (fractol->current_range > 8)
		fractol->current_range = 0;
	ft_default(fractol);
	return (1);
}

void	ft_load_range_set(t_fractol *fractol)
{
	fractol->ranges[0].real = -0.4;
	fractol->ranges[0].imagin = 0.6;
	fractol->ranges[1].real = 0.285;
	fractol->ranges[1].imagin = 0;
	fractol->ranges[2].real = 0.285;
	fractol->ranges[2].imagin = 0.01;
	fractol->ranges[3].real = 0.45;
	fractol->ranges[3].imagin = 0.148;
	fractol->ranges[4].real = -0.70176;
	fractol->ranges[4].imagin = -0.3842;
	fractol->ranges[5].real = -0.835;
	fractol->ranges[5].imagin = -0.2321;
	fractol->ranges[6].real = -0.8;
	fractol->ranges[6].imagin = 0.156;
	fractol->ranges[7].real = -0.7269;
	fractol->ranges[7].imagin = 0.1889;
	fractol->ranges[8].real = -0.8;
	fractol->ranges[8].imagin = -0.8;
}

int	ft_new_pallete(t_fractol *fractol)
{
	fractol->transformation.c_arr[0][0] = -60;
	fractol->transformation.c_arr[0][1] = 3;
	fractol->transformation.c_arr[0][2] = 2;
	fractol->transformation.c_arr[1][0] = 15;
	fractol->transformation.c_arr[1][1] = 3;
	fractol->transformation.c_arr[1][2] = 1;
	fractol->transformation.c_arr[2][0] = 18;
	fractol->transformation.c_arr[2][1] = 0;
	fractol->transformation.c_arr[2][2] = 0;
	return (1);
}
