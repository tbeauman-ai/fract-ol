/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:01:28 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/19 21:21:33 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

void	choose_fractal(t_env *e, char ens)
{
	char	*ensembles;
	void	(*draw_functions[6])(struct s_env *);
	int		(*palettes[6])(int, struct s_env *);
	int		i;

	draw_functions[0] = &draw_julia;
	draw_functions[1] = &draw_burning_ship;
	draw_functions[2] = &draw_newton;
	draw_functions[3] = &draw_burning_julia;
	draw_functions[4] = &draw_mandelbrot;
	draw_functions[5] = &draw_tricorn;
	palettes[0] = &palette_4;
	palettes[1] = &palette_2;
	palettes[2] = &palette_newton;
	palettes[3] = &palette_4;
	palettes[4] = &palette_1;
	palettes[5] = &palette_1;
	ensembles = "jbnimt";
	i = -1;
	while (ensembles[++i])
	{
		if (ensembles[i] == ens)
		{
			e->palette = palettes[i];
			e->draw_fract = draw_functions[i];
		}
	}
}

void	init_newton(t_env *e)
{
	e->newton_roots.r1.re = 1;
	e->newton_roots.r1.im = 0;
	e->newton_roots.r2.re = -1 / 2;
	e->newton_roots.r2.im = sqrt(3) / 2;
	e->newton_roots.r3.re = -1 / 2;
	e->newton_roots.r3.im = sqrt(3) / -2;
	e->nb_it = 10;
}

void	init(t_env *e, char ens)
{
	choose_fractal(e, ens);
	e->nb_it = 50;
	e->pixel_size = 0.01;
	e->re_min = -3;
	e->re_max = 3;
	e->im_min = -2;
	e->im_max = 2;
	e->ens = ens;
	e->puissance = 2;
	e->jul.re = 0;
	e->jul.im = 0;
	e->fix_julia = 0;
	if (ens == 'n')
		init_newton(e);
}

int	main(int ac, char **av)
{
	t_env e;

	e.mlx = mlx_init();
	if (!e.mlx)
		return (write(2, "connection error\n", 17), 0);
	e.win = mlx_new_window(e.mlx, 600, 400, "fractol");
	if (!e.win)
		return (write(2, "window error\n", 13), 0);
	e.img = mlx_new_image(e.mlx, 600, 400);
	if (!e.mlx)
		return (write(2, "image error\n", 12), 0);
	e.img_address = mlx_get_data_addr(e.img, &e.bits_per_pixel, &e.line_length,
			&e.endian);
	if (ac == 1)
		display_menu(&e);
	else
	{
		init(&e, av[1][0]);
		e.draw_fract(&e);
	}
	mlx_mouse_hook(e.win, &mouse_roll, &e);
	mlx_key_hook(e.win, &key_pressed, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, &motion_hook, &e);
	mlx_loop(e.mlx);
	clear_mlx(&e);
	return (0);
}