/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:01:28 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/16 13:07:19 by tbeauman         ###   ########.fr       */
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

void    putpixel(int x, int y, t_env *e, int i)
{
    int     *iimg_addr;

    (void)i;
    if (x + y * 400 > 600 * 400 || x > 599 || y > 399 || x < 0 || y < 0)
        return ;
    iimg_addr = (int*)e->img_address;
    iimg_addr[x + y * 600] = e->palette(i, e);
    e->img_address = (char*)iimg_addr;
}

double  module(t_complex z)
{
    return (sqrt(z.re * z.re + z.im * z.im));
}

t_complex   cpx_mult(t_complex a, t_complex b)
{
    t_complex   ret;

    ret.re = a.re * b.re - a.im * b.im;
    ret.im = a.re * b.im + a.im * b.re;
    return (ret);
}

t_complex   cpx_pow(t_complex a, int n)
{
    t_complex   id;

    id.re = 1;
    id.im = 0;
    if (n == 0)
        return (id);
    return (cpx_mult(a, cpx_pow(a, n - 1)));
}

t_complex   cpx_div(t_complex a, t_complex b)
{
    t_complex   ret;

    ret.re = 0;
    ret.im = 0;
    if (b.re == 0 && b.im == 0)
        return (ret);
    ret.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
    ret.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
    return (ret);
}

t_complex   cpx_inv(t_complex a)
{
    t_complex   one;

    one.re = 1;
    one.im = 0;
    return (cpx_div(one, a));
}

t_complex   mandelbrot_rec(t_complex z, t_complex c, t_env *e)
{
    t_complex   ret;
    t_complex   z_2;
    int         i;

    i = 1;
    z_2 = z;
    while (i++ < abs(e->puissance))
        z_2 = cpx_mult(z, z_2);
    if (e->puissance < 0)
        z_2 = cpx_inv(z_2);
    if (e->puissance == 0)
    {
        z_2.re = 1;
        z_2.im = 0;
    }
    ret.re = z_2.re + c.re;
    ret.im = z_2.im + c.im;
    return (ret);
}

int     is_escaping(t_complex z, t_complex c, int nb_it, t_env *e)
{
    if (module(z) > 2 || nb_it <= 0)
        return (e->nb_it - nb_it);
    z = mandelbrot_rec(z, c, e);
    return (is_escaping(z, c, nb_it - 1, e));
}

void    draw_mandelbrot(t_env *e)
{
    int     x;
    int     y;
    t_complex   c;
    int     i;
    t_complex   z0;

    z0.re = 0;
    z0.im = 0;
    x = 0;
    while (x < 600)
    {
        y = 0;
        while (y < 400)
        {
            c.re = x * e->pixel_size + e->re_min;
            c.im = y * e->pixel_size + e->im_min;
            i = is_escaping(z0, c, e->nb_it, e);
            if (i < e->nb_it && i)
                putpixel(x, y, e, i);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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
    // mlx_mouse_hook(e.win, &mouse_roll, &e);
    mlx_key_hook(e.win, &key_pressed, &e);
    mlx_hook(e.win, MotionNotify, PointerMotionMask, &motion_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}