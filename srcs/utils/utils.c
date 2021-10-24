/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:22:59 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 12:23:00 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_error(const char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_write_hint(void)
{
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "Please enter one of avalable fractals name:\n", 45);
	write(1, "\n", 1);
	write(1, "	Julia\n", 8);
	write(1, "	Mandelbrot\n", 13);
	write(1, "	Burning ship\n", 15);
	write(1, "	Tunnel\n", 9);
	write(1, "\n", 1);
	write(1, "./fractol <name> -x=<double real> -y=<double imagine>", 54);
	write(1, " <-h=<num> -w=<num> -i=<num>\n", 29);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_default(t_fractol *fractol)
{
	fractol->c.real = fractol->ranges[fractol->current_range].real;
	fractol->c.imagin = fractol->ranges[fractol->current_range].imagin;
	fractol->menu = 0;
	fractol->is_changed = 1;
	fractol->min.real = -2.0;
	fractol->min.imagin = -2.0;
	fractol->max.real = 2.0;
	fractol->max.imagin = 2.0;
	fractol->transformation.zoom = 1.0;
	fractol->transformation.c_arr[0][0] = 9;
	fractol->transformation.c_arr[0][1] = 3;
	fractol->transformation.c_arr[0][2] = 0;
	fractol->transformation.c_arr[1][0] = 15;
	fractol->transformation.c_arr[1][1] = 2;
	fractol->transformation.c_arr[1][2] = 1;
	fractol->transformation.c_arr[2][0] = 8.5;
	fractol->transformation.c_arr[2][1] = 3;
	fractol->transformation.c_arr[2][2] = 2;
}

int	ft_valid(char *str, char *needle)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	if (ft_strnstr(str, needle, 3))
	{
		i += 3;
		while (ft_isdigit(str[i]) || str[i] == '.'
			|| (str[i] == '-' && i == 3))
			i++;
		if (i == len)
			return (1);
		ft_error("Flags: -x=<float> -y=<float> -h=<int> -w=<int> -i=<int>");
		return (0);
	}
	else
		return (0);
}

double	ft_atod(const char *arg)
{
	char	min;
	int		i;
	int		decimals;
	double	res;

	i = 0;
	decimals = 0;
	res = 0;
	min = 1;
	while (ft_isspace(arg[i]))
		i++;
	if (min == 1 && arg[i] == '-')
	{
		min = -1;
		i += 2;
	}
	while (arg[i] && ft_isdigit(arg[i]))
		res = res * 10 + min * (arg[i++] - '0');
	if (arg[i] == '.')
		i++;
	while (arg[i + decimals] && ft_isdigit(arg[i + decimals]))
		res = res * 10 + min * (arg[i + decimals++] - '0');
	while (decimals--)
		res /= 10;
	return (res);
}
