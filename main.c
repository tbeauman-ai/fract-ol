/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:01:28 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/18 18:16:17 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include <stdio.h>
# include <math.h>

void    init(t_env *e, char ens)
{
    e->nb_it = 50;
    e->pixel_size = 0.01;
    e->re_min = -3;
    e->re_max = 3;
    e->im_min = -2;
    e->im_max = 2;
    e->ens = ens;
    e->puissance = 2;
    e->palette = &palette_4;
}

// int     main(void)
// {
//     int     i = -5;

//     while (i <= 5)
//     {printf("%d:%d ; ", i, abs(i));
//     i++;}
//     return (0);
// }

int     main(int ac, char **av)
{
    t_env   e;

    if (ac == 1)
    {
        printf("argument needed\n");
        return (0);
    }
    e.mlx = mlx_init();
    if (!e.mlx)
        printf ( "connection error" );
    e.win = mlx_new_window(e.mlx, 600, 400, "fractol");
    if (!e.win)
        printf ( "window error" );
    e.img = mlx_new_image(e.mlx, 600, 400);
    if (!e.mlx)
        printf ( "image error" );
    e.img_address = mlx_get_data_addr(e.img, &e.bits_per_pixel, &e.line_length, &e.endian);
    init(&e, av[1][0]);
    draw_mandelbrot(&e);
    mlx_mouse_hook(e.win, &mouse_hook, &e);
    mlx_key_hook(e.win, &key_pressed, &e);
    mlx_hook(e.win, MotionNotify, PointerMotionMask, &motion_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}