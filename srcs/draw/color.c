/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:37:59 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 11:54:40 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_change_colorset(t_fractol *fractol, int set_i, int i_i, char op)
{
	if (op == 1)
		fractol->transformation.c_arr[set_i][i_i]++;
	else if (!op)
		fractol->transformation.c_arr[set_i][i_i]--;
	printf("%.f %.f %.f\n%.f %.f %.f\n%.f %.f %.f\n",
		fractol->transformation.c_arr[0][0],
		fractol->transformation.c_arr[0][1],
		fractol->transformation.c_arr[0][2],
		fractol->transformation.c_arr[1][0],
		fractol->transformation.c_arr[1][1],
		fractol->transformation.c_arr[1][2],
		fractol->transformation.c_arr[2][0],
		fractol->transformation.c_arr[2][1],
		fractol->transformation.c_arr[2][2]);
	return (1);
}

int	ft_switch_set(t_fractol *fractol)
{
	float	*tmp;
	float	*tmp2;

	tmp = fractol->transformation.c_arr[0];
	tmp2 = fractol->transformation.c_arr[1];
	fractol->transformation.c_arr[0]
		= fractol->transformation.c_arr[2];
	fractol->transformation.c_arr[1] = tmp;
	fractol->transformation.c_arr[2] = tmp2;
	return (1);
}
