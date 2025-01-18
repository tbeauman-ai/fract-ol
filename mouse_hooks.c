/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:46 by tbeauman          #+#    #+#             */
/*   Updated: 2025/01/17 19:07:49 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    zoom_out(int x, int y, t_env *e)
{
    double  re_m;
    double  im_m;
    double  old[4];

    old[0] = e->re_min;
    old[1] = e->re_max;
    old[2] = e->im_min;
    old[3] = e->im_max;
    re_m = e->re_min + x * (e->re_max - e->re_min) / 600;
    im_m = e->im_min + y * (e->im_max - e->im_min) / 400;
    e->pixel_size *= 1.25;
    e->nb_it -= 2;
    e->re_min = re_m - (old[1] - old[0]) * (1.25 / 2); 
    e->re_max = re_m + (old[1] - old[0]) * (1.25 / 2); 
    e->im_min = im_m - (old[3] - old[2]) * (1.25 / 2); 
    e->im_max = im_m + (old[3] - old[2]) * (1.25 / 2); 
}

void    zoom_in(int x, int y, t_env *e)
{
    double  re_m;
    double  im_m;
    double  old[4];

    old[0] = e->re_min;
    old[1] = e->re_max;
    old[2] = e->im_min;
    old[3] = e->im_max;
    re_m = e->re_min + x * (e->re_max - e->re_min) / 600;
    im_m = e->im_min + y * (e->im_max - e->im_min) / 400;
    e->pixel_size /= 1.25;
    e->nb_it += 2;
    e->re_min = re_m - (old[1] - old[0]) / 2.5; 
    e->re_max = re_m + (old[1] - old[0]) / 2.5; 
    e->im_min = im_m - (old[3] - old[2]) / 2.5; 
    e->im_max = im_m + (old[3] - old[2]) / 2.5; 
}

int     mouse_hook(int bt, int x, int y, t_env *e)
{
    if (e->ens == 0)
        return (0);
    if (bt == SCROLL_DOWN)
    {
        clear_image(&e->img_address);
        zoom_out(x, y, e);
    }
    if (bt == SCROLL_UP)
    {
        clear_image(&e->img_address);
        zoom_in(x, y, e);
    }
    mlx_clear_window(e->mlx, e->win);
    draw_mandelbrot(e);
    return (1);
}