/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:08:52 by dwulfe            #+#    #+#             */
/*   Updated: 2021/09/12 11:58:09 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_get_additional(char **arr, t_fractol *fractol)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_valid(arr[i], "-x="))
			fractol->c.real = ft_atod(*(arr + i) + 3);
		else if (ft_valid(arr[i], "-y="))
			fractol->c.imagin = ft_atod(*(arr + i) + 3);
		else if (ft_valid(arr[i], "-h="))
			fractol->h = ft_atoi(*(arr + i) + 3);
		else if (ft_valid(arr[i], "-w="))
			fractol->w = ft_atoi(*(arr + i) + 3);
		else if (ft_valid(arr[i], "-i="))
			fractol->max_iter = ft_atoi(*(arr + i) + 3);
		else
			ft_error("Not valid additional args!\n <flag>=<double>");
		i++;
	}
}

static void	ft_init_color(t_fractol *fractol)
{
	fractol->transformation.c_arr = malloc(sizeof(float **) * 3);
	fractol->transformation.c_arr[0] = malloc(sizeof(float *) * 3);
	fractol->transformation.c_arr[1] = malloc(sizeof(float *) * 3);
	fractol->transformation.c_arr[2] = malloc(sizeof(float *) * 3);
}

static void	ft_init(t_fractol *fractol, int argc, char **argv)
{
	ft_load_range_set(fractol);
	fractol->max_iter = 100;
	fractol->h = 0;
	fractol->w = 0;
	fractol->current_range = 0;
	ft_init_color(fractol);
	ft_default(fractol);
	if (argc > 2)
		ft_get_additional(argv + 2, fractol);
	if (!fractol->w || !fractol->h)
	{
		fractol->h = 1000;
		fractol->w = 1000;
	}
	fractol->mlx.ptr = mlx_init();
	fractol->mlx.win = mlx_new_window(fractol->mlx.ptr,
			fractol->w, fractol->h, "mlx 42");
	fractol->img.img = mlx_new_image(fractol->mlx.ptr,
			fractol->w, fractol->h);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
}

static int	ft_loop(t_fractol *fractol)
{
	if (fractol->is_changed)
	{
		if (fractol->menu)
			ft_display_menu(fractol);
		else
			ft_draw(fractol);
		fractol->is_changed = 0;
		mlx_string_put(fractol->mlx.ptr, fractol->mlx.win,
			(fractol->w / 4) * 3, (fractol->h / 3) * 2.7, 0xc0c0c0,
			"Close/Open Menu - M");
	}
	return (1);
}	

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 1 || !ft_calculation(&fractol, argv[1]))
		ft_write_hint();
	ft_init(&fractol, argc, argv);
	mlx_loop_hook(fractol.mlx.ptr, ft_loop, &fractol);
	mlx_hook(fractol.mlx.win, 2, 0, ft_handle_key, &fractol);
	mlx_hook(fractol.mlx.win, 17, 0, ft_exit, &fractol);
	mlx_hook(fractol.mlx.win, 4, 0, ft_zoom, &fractol);
	mlx_hook(fractol.mlx.win, 3, 0, ft_remove_key, &fractol);
	mlx_loop(fractol.mlx.ptr);
	return (0);
}
